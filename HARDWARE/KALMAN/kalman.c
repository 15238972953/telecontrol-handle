#include "kalman.h"



// ��ʼ���������˲���
void KalmanFilter_Init(KalmanFilter *kf, double q, double r, double initial_x, double initial_p) {
    kf->q = q;
    kf->r = r;
    kf->x = initial_x;
    kf->p = initial_p;
		kf->k = 0;
}

// �������˲����²���
double KalmanFilter_Update(KalmanFilter *kf, double measurement) {
    // Ԥ�ⲽ��
    kf->p = kf->p + kf->q;

    // ���㿨��������
    kf->k = kf->p / (kf->p + kf->r);

    // ����״̬����ֵ
    kf->x = kf->x + kf->k * (measurement - kf->x);

    // ���¹������Э����
    kf->p = (1 - kf->k) * kf->p;

    return kf->x;
}
