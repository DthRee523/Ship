#ifndef EONIC_H
#define EONIC_H

#define HT_OK 0
#define HT_ERR_INVALID_PARAM 1
#define HT_ERR_INVALID_STATE 2
#define HT_ERR_FILE_NOT_FOUND 3
#define HT_ERR_DATA_NOT_FOUND 4
#define HT_ERR_INVALID_LICENSE 5
#define HT_ERR_INVALID_DATA 6
#define HT_ERR_INTERNAL 1000

#define HT_BEDTYPE_0 0
#define HT_BEDTYPE_1 1
#define HT_BEDTYPE_2 2
#define HT_BEDTYPE_3 3
#define HT_BEDTYPE_4 4
#define HT_BEDTYPE_5 5
#define HT_BEDTYPE_6 6
#define HT_BEDTYPE_7 7
#define HT_BEDTYPE_8 8

#ifdef _WRS_KERNEL // VxWorks
#define EONIC_API_EXPORT
#elif defined(EONIC_LIB)
#define EONIC_API_EXPORT __declspec(dllexport)
#else
#define EONIC_API_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief ht_Init
 *   海图初始化
 * @param dataPath
 *   数据文件夹路径。
 *   如："/mmc:0/ECDIS"
 * @param screenCount
 *   屏幕数量，默认值为1。
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_FILE_NOT_FOUND 找不到海图数据文件
 */
EONIC_API_EXPORT int ht_Init(const char* dataPath, int screenCount = 1);

/**
 * @brief ht_GetDeviceID
 *   获取设备识别码
 * @param deviceID
 *   输出设备识别码，长度为16的字符串
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INTERNAL 获取失败
 */
EONIC_API_EXPORT int ht_GetDeviceID(char* deviceID);

/**
 * @brief ht_GetLicenseState
 *   获取许可状态
 * @return
 *   返回许可状态：
 *   0 许可验证成功
 *   1 未输入许可
 *   2 许可验证失败
 *   100 其它错误
 */
EONIC_API_EXPORT int ht_GetLicenseState();

/**
 * @brief ht_Set_License
 *   设置本机许可。应在调用ht_Init前调用。
 * @param license
 *   许可序列号，长度为28的字符串
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INVALID_PARAM 许可序列号格式错误
 *   HT_ERR_INVALID_LICENSE 许可验证失败
 */
EONIC_API_EXPORT int ht_Set_License(const char* license);

/**
 * @brief ht_SetDebugLevel
 *   设置调试等级。
 * @param level
 *   调试等级：
 *   0 不显示调试信息
 *   1 显示调试信息
 * @return
 *   返回错误码：
 *   HT_OK 成功
 */
EONIC_API_EXPORT int ht_SetDebugLevel(int level);

/**
 * @brief ht_Set_Viewport
 *   设置海图绘图区域
 * @param left
 *   海图绘图区域左边缘距离屏幕左边缘的距离。单位：像素
 * @param bottom
 *   海图绘图区域下边缘距离屏幕下边缘的距离。单位：像素
 * @param width
 *   海图绘图区域的宽度。单位：像素
 * @param height
 *   海图绘图区域的高度。单位：像素
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 尺寸小于0
 */
EONIC_API_EXPORT int ht_Set_Viewport(int left, int bottom, int width, int height);

/**
 * @brief ht_Palette
 *   设置海图配色方案
 *   应在ht_Draw_Flash前调用
 * @param paletteId 配色方案编号
 *   0 - 日间
 *   1 - 黑夜
 *   2 - 纯海岸线
 *   3 - 高程图
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 配色方案编号无效
 */
EONIC_API_EXPORT int ht_Palette(int paletteId);

/**
 * @brief ht_Get_Palette
 *   获取海图配色方案
 * @param paletteId 返回配色方案编号
 *   0 - 日间
 *   1 - 黑夜
 *   2 - 纯海岸线
 *   3 - 高程图
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 */
EONIC_API_EXPORT int ht_Get_Palette(int* paletteId);

/**
 * @brief ht_Add_clom
 *   增加元素（包括增加载机、增加目标）
 *   暂未使用
 */
void ht_Add_clom();

/**
 * @brief ht_Draw_Flash
 *   绘制海图
 * @param screenId
 *   当前屏幕编号，默认值为0。
 *   应满足：0 <= screenId < 屏幕数量
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 屏幕编号无效
 */
EONIC_API_EXPORT int ht_Draw_Flash(int screenId = 0);

/**
 * @brief ht_TB
 *   鼠标事件回调函数
 * @param x
 *   x坐标
 * @param y
 *   y坐标
 * @param buttvalue
 *   按键状态：
 *   0 - 无按键
 *   1 - 按键1弹起
 *   2 - 按键1按下
 *   3 - 按键2弹起
 *   4 - 按键2按下
 *   5 - 按键3弹起
 *   6 - 按键3按下
 */
EONIC_API_EXPORT void ht_TB(int x, int y, int buttvalue);

/**
 * @brief ht_Get_Bedtype
 *   获取海底底质类型
 * @param latitude
 *   纬度，单位：°
 * @param longitude
 *   经度，单位：°
 * @param bedType
 *   输出底质类型
 *   HT_BEDTYPE_0 泥
 *   HT_BEDTYPE_1 沙
 *   HT_BEDTYPE_2 石
 *   HT_BEDTYPE_3 砾
 *   HT_BEDTYPE_4 岩
 *   HT_BEDTYPE_5 粘土
 *   HT_BEDTYPE_6 火山灰
 *   HT_BEDTYPE_7 贝
 *   HT_BEDTYPE_8 珊
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_DATA_NOT_FOUND 查询位置无数据
 */
EONIC_API_EXPORT int ht_Get_Bedtype(double latitude, double longitude, int* bedType);

/**
 * @brief ht_Get_Depth
 *   获取海底深度
 * @param latitude
 *   纬度，单位：°
 * @param longitude
 *   经度，单位：°
 * @param depth
 *   输出海底深度
 * @return
 *   返回错误码：
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_DATA_NOT_FOUND 查询位置无数据
 */
EONIC_API_EXPORT int ht_Get_Depth(double latitude, double longitude, double* depth);

/**
 * @brief ht_BL_to_UI
 *   坐标转换函数，将经纬度转换为屏幕坐标。
 * @param latitude
 *   纬度，单位：°
 * @param longitude
 *   经度，单位：°
 * @param x
 *   输出x坐标，原点为海图显示中心，向右为正。单位：像素
 * @param y
 *   输出y坐标，原点为海图显示中心，向上为正。单位：像素
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 输入参数超出范围
 */
EONIC_API_EXPORT int ht_BL_to_UI(double latitude, double longitude, double* x, double* y);

/**
 * @brief ht_UI_to_BL
 *   坐标转换函数，将屏幕坐标转换为经纬度。
 * @param x
 *   x坐标，原点为海图显示中心，向右为正。单位：像素
 * @param y
 *   y坐标，原点为海图显示中心，向上为正。单位：像素
 * @param latitude
 *   输出纬度，单位：°
 * @param longitude
 *   输出经度，单位：°
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 输入参数超出范围
 */
EONIC_API_EXPORT int ht_UI_to_BL(double x, double y, double* latitude, double* longitude);

/**
 * @brief ht_Measure
 *   测量两点的相对距离和方位。
 * @param b1
 *   第1点纬度，单位：°
 * @param l1
 *   第1点经度，单位：°
 * @param b2
 *   第2点纬度，单位：°
 * @param l2
 *   第2点经度，单位：°
 * @param distance
 *   输出距离，单位：m
 * @param angle
 *   输出方位，单位：°
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 输入参数超出范围
 */
EONIC_API_EXPORT int ht_Measure(double b1, double l1, double b2, double l2, double* distance, double* angle);

/**
 * @brief ht_Direct
 *   给定第1点的位置、距离和方位，推算第2点的位置。
 * @param b1
 *   第1点纬度，单位：°
 * @param l1
 *   第1点经度，单位：°
 * @param distance
 *   距离，单位：m
 * @param angle
 *   方位，单位：°
 * @param b2
 *   输出第2点纬度，单位：°
 * @param l2
 *   输出第2点经度，单位：°
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_STATE 海图未初始化
 *   HT_ERR_INVALID_PARAM 输入参数超出范围
 */
EONIC_API_EXPORT int ht_Direct(double b1, double l1, double distance, double angle, double* b2, double* l2);

/**
 * @brief HtIconInfo
 *   图标信息结构
 */
struct HtIconInfo {
    int iconId; // 图标ID，-1为无效
    int width; // 宽度，单位：像素
    int height; // 高度，单位：像素
};

/**
 * @brief ht_Init_Icon_WEBP
 *   初始化WEBP格式图标
 * @param path
 *   图标文件路径
 * @param iconInfo
 *   输出图标信息，包括图标ID、宽度、高度等
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_DATA 图标文件读取失败
 */
EONIC_API_EXPORT int ht_Init_Icon_WEBP(const char* path, HtIconInfo* iconInfo);

/**
 * @brief ht_Draw_Icon_UI
 *   在屏幕指定位置绘制图标
 * @param iconId
 *   图标ID，参见ht_Init_Icon_*的输出
 * @param x
 *   x坐标，原点为海图显示中心，向右为正。单位：像素
 * @param y
 *   y坐标，原点为海图显示中心，向上为正。单位：像素
 * @param scale
 *   缩放比例，单位：倍数
 * @param angle
 *   旋转角，单位：°
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_PARAM 图标ID无效
 */
EONIC_API_EXPORT int ht_Draw_Icon_UI(int iconId, double x, double y, double scale, double angle);

/**
 * @brief ht_Draw_Icon_BL
 *   在指定经纬度绘制图标
 * @param iconId
 *   图标ID，参见ht_Init_Icon_*的输出
 * @param latitude
 *   纬度，单位：°
 * @param longitude
 *   经度，单位：°
 * @param scale
 *   缩放比例，单位：倍数
 * @param angle
 *   旋转角，单位：°
 * @return
 *   HT_OK 成功
 *   HT_ERR_INVALID_PARAM 图标ID无效
 */
EONIC_API_EXPORT int ht_Draw_Icon_BL(int iconId, double latitude, double longitude, double scale, double angle);

#ifdef _WRS_KERNEL // VxWorks
/**
 * 获取当前缩放比例下，每个像素点代表的距离(m),与ScaleValue（+-）标尺值同步更新
 */
extern int GetmPixel();
/**
 * 获取当前屏幕中心点坐标
 */
extern void GetCentralPoint(double * lat, double * lon);

#else // Windows
/**
 * 设置当前缩放比例下，每个像素点代表的距离(m),与ScaleValue（+-）标尺值同步更新
 */
EONIC_API_EXPORT void ht_Set_mPixel(int mPixel);
/**
 * 设置当前屏幕中心点坐标
 */
EONIC_API_EXPORT void ht_Set_Central_Point(double lat, double lon);

#endif

#ifdef __cplusplus
}
#endif

#endif
