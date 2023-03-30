#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    QSettings * configIniRead = new QSettings("config.ini",QSettings::IniFormat);//初始化读取Ini文件对象
    server = QHostAddress(configIniRead->value("server/ip").toString());//IP地址
    localhost = QHostAddress(configIniRead->value("localhost/ip").toString());
    socket1 = new QUdpSocket(this);//航行信息
    socket1->bind(localhost, this->hxPort, QUdpSocket::ShareAddress);
    connect (socket1, &QUdpSocket::readyRead, this, &Network::getHxData);
    socket2 = new QUdpSocket(this);//基本数据
    socket2->bind(localhost, this->basePort, QUdpSocket::ShareAddress);
    connect (socket2, &QUdpSocket::readyRead, this, &Network::getBaseData);
    socket3 = new QUdpSocket(this);//雨刮器
    socket3->bind(localhost, this->data1Port, QUdpSocket::ShareAddress);
    connect (socket3, &QUdpSocket::readyRead, this, &Network::getNetData1);
    socket4 = new QUdpSocket(this);
    socket4->bind(localhost, this->foghornPort, QUdpSocket::ShareAddress);
    socket5 = new QUdpSocket(this);
    socket5->bind(localhost, this->windowHeatingPort, QUdpSocket::ShareAddress);
    connect(socket5, &QUdpSocket::readyRead, this, &Network::getNetData3);
    socket6 = new QUdpSocket(this);//警铃
    socket6->bind(localhost, this->alarmBellPort, QUdpSocket::ShareAddress);
    socket7 = new QUdpSocket(this);
    socket7->bind(localhost, this->shipLightPort, QUdpSocket::ShareAddress);
    connect(socket7, &QUdpSocket::readyRead, this, &Network::getNetData5);
}

void Network::getBaseData()//基本数据
{
    QByteArray buffer;
    buffer.resize(19);
    socket2->readDatagram(buffer.data(), buffer.size());
    if (static_cast<quint8>(buffer[0]) == 0xA1)
    {
        memcpy(&this->lat, buffer.mid(1, 8).data(), 8);
        memcpy(&this->lon, buffer.mid(9, 8).data(), 8);
        this->speed = static_cast<quint8>(buffer[17]);
        this->sx = static_cast<quint8>(buffer[18]);
    }
    emit this->sendBaseData(this->lat, this->lon, this->speed, this->sx);
}

void Network::getHxData()//航行数据
{
    QByteArray buffer;
    buffer.resize(29);
    socket1->readDatagram(buffer.data(), buffer.size());
    if (static_cast<quint8>(buffer[0]) == 0xA0)
    {
        this->power_left_state = static_cast<quint8>(buffer[1]);
        this->power_left_dw = static_cast<quint8>(buffer[2]);
        int testData = static_cast<quint8>(buffer[3]);
        this->power_left_gk = (double)testData / 100;
        this->power_right_state = static_cast<quint8>(buffer[4]);
        this->power_right_dw = static_cast<quint8>(buffer[5]);
        testData = static_cast<quint8>(buffer[6]);
        this->power_right_gk = (double)testData / 100;
        this->ele1_state_1 = static_cast<quint8>(buffer[7]);
        this->ele1_state = static_cast<quint8>(buffer[8]);
        this->ele1_V = static_cast<quint8>(buffer[9]) * 256 + static_cast<quint8>(buffer[10]);
        this->ele1_A = static_cast<quint8>(buffer[11]) * 256 + static_cast<quint8>(buffer[12]);
        this->ele2_state_2 = static_cast<quint8>(buffer[13]);
        this->ele2_state = static_cast<quint8>(buffer[14]);
        this->ele2_V = static_cast<quint8>(buffer[15]) * 256 + static_cast<quint8>(buffer[16]);
        this->ele2_A = static_cast<quint8>(buffer[17]) * 256 + static_cast<quint8>(buffer[18]);
        this->ele_an_state = static_cast<quint8>(buffer[19]);
        this->ele_an_V = static_cast<quint8>(buffer[20]) * 256 + static_cast<quint8>(buffer[21]);
        this->ele_an_A = static_cast<quint8>(buffer[22]) * 256 + static_cast<quint8>(buffer[23]);
        this->duo_value = static_cast<quint8>(buffer[24]);
        this->duo_value_1 = static_cast<quint8>(buffer[25]);
        this->ym_value = static_cast<quint8>(buffer[26]);
        this->ym_value_1 = static_cast<quint8>(buffer[27]);
        this->ry_value = static_cast<quint8>(buffer[28]);
    }
    emit this->sendHxData(this->power_left_state, this->power_left_dw, this->power_left_gk,
                          this->power_right_state, this->power_right_dw, this->power_right_gk,
                          this->ele1_state_1, this->ele1_state, this->ele1_V, this->ele1_A,
                          this->ele2_state_2, this->ele2_state, this->ele2_V, this->ele2_A,
                          this->ele_an_state, this->ele_an_V, this->ele_an_A, this->duo_value,
                          this->duo_value_1, this->ym_value, this->ym_value_1, this->ry_value);
    //qDebug() << this->ele2_A << " " << this->power_right_gk;
}

void Network::getNetData1()
{
    QByteArray buffer;
    buffer.resize(5);
    socket3->readDatagram(buffer.data(), buffer.size());
    if (static_cast<quint8>(buffer[0]) == 0xA2)
    {
        emit this->sendData1(buffer);
    }
}

void Network::getNetData3()
{
    QByteArray buffer;
    buffer.resize(9);
    socket5->readDatagram(buffer.data(), buffer.size());
    if (static_cast<quint8>(buffer[0]) == 0xA6)
    {
        emit this->sendDate3(buffer);
    }
}

void Network::getNetData5()
{
    QByteArray buffer;
    buffer.resize(4);
    socket7->readDatagram(buffer.data(), buffer.size());
    if (static_cast<quint8>(buffer[0]) == 0xA4)
    {
        emit this->sendData5(buffer);
    }
}

void Network::sendNetData1(QByteArray data)
{
    socket3->writeDatagram(data.data(), data.size(), server, this->data1Port);
}

void Network::sendNetData2(QByteArray data)
{
    socket4->writeDatagram(data.data(), data.size(), server, this->foghornPort);
}

void Network::sendNetData3(QByteArray data)
{
    socket5->writeDatagram(data.data(), data.size(), server, this->windowHeatingPort);
}

void Network::sendNetData4(QByteArray data)
{
    socket6->writeDatagram(data.data(), data.size(), server, this->alarmBellPort);
}

void Network::sendNetData5(QByteArray data)
{
    socket7->writeDatagram(data.data(), data.size(), server, this->shipLightPort);
}
