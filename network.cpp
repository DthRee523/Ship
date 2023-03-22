#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    QSettings * configIniRead = new QSettings("config.ini",QSettings::IniFormat);//初始化读取Ini文件对象
    server = QHostAddress(configIniRead->value("server/ip").toString());//IP地址
    socket1 = new QUdpSocket(this);
    socket1->bind(QHostAddress::AnyIPv4, this->hxPort, QUdpSocket::ShareAddress);
    connect (socket1, &QUdpSocket::readyRead, this, &Network::getHxData);
    socket2 = new QUdpSocket(this);
    socket2->bind(QHostAddress::AnyIPv4, this->basePort, QUdpSocket::ShareAddress);
    connect (socket2, &QUdpSocket::readyRead, this, &Network::getBaseData);
}

void Network::getBaseData()//基本数据
{
    QByteArray buffer;
    buffer.resize(19);
    socket2->readDatagram(buffer.data(), buffer.size());
    if (static_cast<quint8>(buffer[0]) == 0xA1)
    {
        this->lat = static_cast<quint64>(buffer.mid(1, 8)[0]);
        this->lon = static_cast<quint64>(buffer.mid(9, 8)[0]);
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
        this->power_left_gk = static_cast<quint8>(buffer[3]);
        this->power_right_state = static_cast<quint8>(buffer[4]);
        this->power_right_dw = static_cast<quint8>(buffer[5]);
        this->power_right_gk = static_cast<quint8>(buffer[6]);
        this->ele1_state_1 = static_cast<quint8>(buffer[7]);
        this->ele1_state = static_cast<quint8>(buffer[8]);
        this->ele1_V = static_cast<quint8>(buffer[9]) * 256 + static_cast<quint8>(buffer[10]);
        this->ele2_A = static_cast<quint8>(buffer[11]) * 256 + static_cast<quint8>(buffer[12]);
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
}
