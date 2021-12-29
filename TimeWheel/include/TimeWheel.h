#ifndef TIMEWHEEL_H
#define TIMEWHEEL_H

#ifdef _WIN32
#	include <WinSock2.h>
#else
#	include <netinet/in.h>
#endif // WIN32

//#include<functional>
#include <iostream>
#include<list>
#include<thread>
#include<mutex>
#include <functional>
// ��Ϣ�����С
#define BUFFER_SIZE 64

using namespace std;
// typedef long long __int64;
static auto start_time = std::chrono::system_clock::now();
//static auto start_test = std::chrono::system_clock::now();

/** ʱ��ṹ��
 *	ms_pos ����
 *	s_pos ��
 *	min_pos ����
 *	hour_pos Сʱ
 *	day_pos ��
 */
typedef struct TimePos_
{
	int ms_pos;
	int s_pos;
	int min_pos;
	int hour_pos;
	int day_pos;
}TimePos;

/** �¼���Ϣ
 *  interval	ʱ����
 *  time_pos	ʱ���ֲ�
 *  address	�ͻ��˵�ַ
 *  sockfd	�ͻ��˾��
 */
typedef struct EventInfo_
{
	__int64 interval;
	std::function<void(int, char*)> call_back;
	TimePos time_pos;
	int timer_id;
	int sockfd;
	std::chrono::high_resolution_clock::time_point my_start_time;

}EventInfo;

class TimeWheel
{
public:
	TimeWheel();
	~TimeWheel();
public:
	/** ��ʼ��ʱ����
     *	step �Ժ���Ϊ��λ����ʾ��ʱ����Сʱ������
	 *	max_time ��ʾ��ʱ�����ܽ��ܵ�����������
	 */
	int initTimerWheel(int step,int max_time);
	
	int generateTimerID();
	
	/** ���Ӷ�ʱ����
     *	sockfd �ͻ����׽���
	 *	interval ��ʱ��� :ms
	 *	call_back ��ʱ�ص�ִ�к���
	 */
	int addTimer(int sockfd, __int64 interval, std::function<void(int, char*)>& call_back);
	
private:
	/** ��ʼ���ṹ��
	 */
	void init();
	
	/** ʱ����ѭ��
	 */
	int doLoop();
	
	/** �����¼�
     *	diff_ms ��ʱʱ��
	 *	einfo �¼�
	 */
	int insertTimer(EventInfo& einfo);
	
	/** ��ȡ�¼���ʱ�����ϵ�λ��
	 *	time_pos ʱ����
	 */
	int getNextTrigerPos(__int64 interval,TimePos& time_pos);

	int getTimerTrigerPos(EventInfo& einfo,TimePos& time_pos);
	
	/** ��ȡʱ����ʱ��
	 */
	__int64 getMS(TimePos& time_pos);
	
	/** ����ʱ���ֲ��ϵ��¼�
	 *	�¼��б�
	 */
	int dealTimeWheeling(std::list<EventInfo> leinfo);
	
	/** ʱ����˯��ʱ��
	 */
	int sleepTime(long interval, TimePos& time_pos);

private:
	std::list<EventInfo> *_pCallbackList;
	std::mutex _mutex;
	TimePos _time_pos;
	int _msCount;
	int _sCount;
	int _minCount;
	int _hourCount;
	int _dayCount;
	int _step_ms;
	int _timer_count;
	int _unit_ms;
};

#endif // !TIMEWHEEL_H

