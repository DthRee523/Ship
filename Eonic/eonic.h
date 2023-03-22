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
 *   ��ͼ��ʼ��
 * @param dataPath
 *   �����ļ���·����
 *   �磺"/mmc:0/ECDIS"
 * @param screenCount
 *   ��Ļ������Ĭ��ֵΪ1��
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_FILE_NOT_FOUND �Ҳ�����ͼ�����ļ�
 */
EONIC_API_EXPORT int ht_Init(const char* dataPath, int screenCount = 1);

/**
 * @brief ht_GetDeviceID
 *   ��ȡ�豸ʶ����
 * @param deviceID
 *   ����豸ʶ���룬����Ϊ16���ַ���
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INTERNAL ��ȡʧ��
 */
EONIC_API_EXPORT int ht_GetDeviceID(char* deviceID);

/**
 * @brief ht_GetLicenseState
 *   ��ȡ���״̬
 * @return
 *   �������״̬��
 *   0 �����֤�ɹ�
 *   1 δ�������
 *   2 �����֤ʧ��
 *   100 ��������
 */
EONIC_API_EXPORT int ht_GetLicenseState();

/**
 * @brief ht_Set_License
 *   ���ñ�����ɡ�Ӧ�ڵ���ht_Initǰ���á�
 * @param license
 *   ������кţ�����Ϊ28���ַ���
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_PARAM ������кŸ�ʽ����
 *   HT_ERR_INVALID_LICENSE �����֤ʧ��
 */
EONIC_API_EXPORT int ht_Set_License(const char* license);

/**
 * @brief ht_SetDebugLevel
 *   ���õ��Եȼ���
 * @param level
 *   ���Եȼ���
 *   0 ����ʾ������Ϣ
 *   1 ��ʾ������Ϣ
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 */
EONIC_API_EXPORT int ht_SetDebugLevel(int level);

/**
 * @brief ht_Set_Viewport
 *   ���ú�ͼ��ͼ����
 * @param left
 *   ��ͼ��ͼ�������Ե������Ļ���Ե�ľ��롣��λ������
 * @param bottom
 *   ��ͼ��ͼ�����±�Ե������Ļ�±�Ե�ľ��롣��λ������
 * @param width
 *   ��ͼ��ͼ����Ŀ�ȡ���λ������
 * @param height
 *   ��ͼ��ͼ����ĸ߶ȡ���λ������
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM �ߴ�С��0
 */
EONIC_API_EXPORT int ht_Set_Viewport(int left, int bottom, int width, int height);

/**
 * @brief ht_Palette
 *   ���ú�ͼ��ɫ����
 *   Ӧ��ht_Draw_Flashǰ����
 * @param paletteId ��ɫ�������
 *   0 - �ռ�
 *   1 - ��ҹ
 *   2 - ��������
 *   3 - �߳�ͼ
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM ��ɫ���������Ч
 */
EONIC_API_EXPORT int ht_Palette(int paletteId);

/**
 * @brief ht_Get_Palette
 *   ��ȡ��ͼ��ɫ����
 * @param paletteId ������ɫ�������
 *   0 - �ռ�
 *   1 - ��ҹ
 *   2 - ��������
 *   3 - �߳�ͼ
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 */
EONIC_API_EXPORT int ht_Get_Palette(int* paletteId);

/**
 * @brief ht_Add_clom
 *   ����Ԫ�أ����������ػ�������Ŀ�꣩
 *   ��δʹ��
 */
void ht_Add_clom();

/**
 * @brief ht_Draw_Flash
 *   ���ƺ�ͼ
 * @param screenId
 *   ��ǰ��Ļ��ţ�Ĭ��ֵΪ0��
 *   Ӧ���㣺0 <= screenId < ��Ļ����
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM ��Ļ�����Ч
 */
EONIC_API_EXPORT int ht_Draw_Flash(int screenId = 0);

/**
 * @brief ht_TB
 *   ����¼��ص�����
 * @param x
 *   x����
 * @param y
 *   y����
 * @param buttvalue
 *   ����״̬��
 *   0 - �ް���
 *   1 - ����1����
 *   2 - ����1����
 *   3 - ����2����
 *   4 - ����2����
 *   5 - ����3����
 *   6 - ����3����
 */
EONIC_API_EXPORT void ht_TB(int x, int y, int buttvalue);

/**
 * @brief ht_Get_Bedtype
 *   ��ȡ���׵�������
 * @param latitude
 *   γ�ȣ���λ����
 * @param longitude
 *   ���ȣ���λ����
 * @param bedType
 *   �����������
 *   HT_BEDTYPE_0 ��
 *   HT_BEDTYPE_1 ɳ
 *   HT_BEDTYPE_2 ʯ
 *   HT_BEDTYPE_3 ��
 *   HT_BEDTYPE_4 ��
 *   HT_BEDTYPE_5 ճ��
 *   HT_BEDTYPE_6 ��ɽ��
 *   HT_BEDTYPE_7 ��
 *   HT_BEDTYPE_8 ɺ
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_DATA_NOT_FOUND ��ѯλ��������
 */
EONIC_API_EXPORT int ht_Get_Bedtype(double latitude, double longitude, int* bedType);

/**
 * @brief ht_Get_Depth
 *   ��ȡ�������
 * @param latitude
 *   γ�ȣ���λ����
 * @param longitude
 *   ���ȣ���λ����
 * @param depth
 *   ����������
 * @return
 *   ���ش����룺
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_DATA_NOT_FOUND ��ѯλ��������
 */
EONIC_API_EXPORT int ht_Get_Depth(double latitude, double longitude, double* depth);

/**
 * @brief ht_BL_to_UI
 *   ����ת������������γ��ת��Ϊ��Ļ���ꡣ
 * @param latitude
 *   γ�ȣ���λ����
 * @param longitude
 *   ���ȣ���λ����
 * @param x
 *   ���x���꣬ԭ��Ϊ��ͼ��ʾ���ģ�����Ϊ������λ������
 * @param y
 *   ���y���꣬ԭ��Ϊ��ͼ��ʾ���ģ�����Ϊ������λ������
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM �������������Χ
 */
EONIC_API_EXPORT int ht_BL_to_UI(double latitude, double longitude, double* x, double* y);

/**
 * @brief ht_UI_to_BL
 *   ����ת������������Ļ����ת��Ϊ��γ�ȡ�
 * @param x
 *   x���꣬ԭ��Ϊ��ͼ��ʾ���ģ�����Ϊ������λ������
 * @param y
 *   y���꣬ԭ��Ϊ��ͼ��ʾ���ģ�����Ϊ������λ������
 * @param latitude
 *   ���γ�ȣ���λ����
 * @param longitude
 *   ������ȣ���λ����
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM �������������Χ
 */
EONIC_API_EXPORT int ht_UI_to_BL(double x, double y, double* latitude, double* longitude);

/**
 * @brief ht_Measure
 *   �����������Ծ���ͷ�λ��
 * @param b1
 *   ��1��γ�ȣ���λ����
 * @param l1
 *   ��1�㾭�ȣ���λ����
 * @param b2
 *   ��2��γ�ȣ���λ����
 * @param l2
 *   ��2�㾭�ȣ���λ����
 * @param distance
 *   ������룬��λ��m
 * @param angle
 *   �����λ����λ����
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM �������������Χ
 */
EONIC_API_EXPORT int ht_Measure(double b1, double l1, double b2, double l2, double* distance, double* angle);

/**
 * @brief ht_Direct
 *   ������1���λ�á�����ͷ�λ�������2���λ�á�
 * @param b1
 *   ��1��γ�ȣ���λ����
 * @param l1
 *   ��1�㾭�ȣ���λ����
 * @param distance
 *   ���룬��λ��m
 * @param angle
 *   ��λ����λ����
 * @param b2
 *   �����2��γ�ȣ���λ����
 * @param l2
 *   �����2�㾭�ȣ���λ����
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_STATE ��ͼδ��ʼ��
 *   HT_ERR_INVALID_PARAM �������������Χ
 */
EONIC_API_EXPORT int ht_Direct(double b1, double l1, double distance, double angle, double* b2, double* l2);

/**
 * @brief HtIconInfo
 *   ͼ����Ϣ�ṹ
 */
struct HtIconInfo {
    int iconId; // ͼ��ID��-1Ϊ��Ч
    int width; // ��ȣ���λ������
    int height; // �߶ȣ���λ������
};

/**
 * @brief ht_Init_Icon_WEBP
 *   ��ʼ��WEBP��ʽͼ��
 * @param path
 *   ͼ���ļ�·��
 * @param iconInfo
 *   ���ͼ����Ϣ������ͼ��ID����ȡ��߶ȵ�
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_DATA ͼ���ļ���ȡʧ��
 */
EONIC_API_EXPORT int ht_Init_Icon_WEBP(const char* path, HtIconInfo* iconInfo);

/**
 * @brief ht_Draw_Icon_UI
 *   ����Ļָ��λ�û���ͼ��
 * @param iconId
 *   ͼ��ID���μ�ht_Init_Icon_*�����
 * @param x
 *   x���꣬ԭ��Ϊ��ͼ��ʾ���ģ�����Ϊ������λ������
 * @param y
 *   y���꣬ԭ��Ϊ��ͼ��ʾ���ģ�����Ϊ������λ������
 * @param scale
 *   ���ű�������λ������
 * @param angle
 *   ��ת�ǣ���λ����
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_PARAM ͼ��ID��Ч
 */
EONIC_API_EXPORT int ht_Draw_Icon_UI(int iconId, double x, double y, double scale, double angle);

/**
 * @brief ht_Draw_Icon_BL
 *   ��ָ����γ�Ȼ���ͼ��
 * @param iconId
 *   ͼ��ID���μ�ht_Init_Icon_*�����
 * @param latitude
 *   γ�ȣ���λ����
 * @param longitude
 *   ���ȣ���λ����
 * @param scale
 *   ���ű�������λ������
 * @param angle
 *   ��ת�ǣ���λ����
 * @return
 *   HT_OK �ɹ�
 *   HT_ERR_INVALID_PARAM ͼ��ID��Ч
 */
EONIC_API_EXPORT int ht_Draw_Icon_BL(int iconId, double latitude, double longitude, double scale, double angle);

#ifdef _WRS_KERNEL // VxWorks
/**
 * ��ȡ��ǰ���ű����£�ÿ�����ص����ľ���(m),��ScaleValue��+-�����ֵͬ������
 */
extern int GetmPixel();
/**
 * ��ȡ��ǰ��Ļ���ĵ�����
 */
extern void GetCentralPoint(double * lat, double * lon);

#else // Windows
/**
 * ���õ�ǰ���ű����£�ÿ�����ص����ľ���(m),��ScaleValue��+-�����ֵͬ������
 */
EONIC_API_EXPORT void ht_Set_mPixel(int mPixel);
/**
 * ���õ�ǰ��Ļ���ĵ�����
 */
EONIC_API_EXPORT void ht_Set_Central_Point(double lat, double lon);

#endif

#ifdef __cplusplus
}
#endif

#endif
