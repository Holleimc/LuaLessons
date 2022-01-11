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
// 消息传输大小
#define BUFFER_SIZE 64

using namespace std;
// typedef long long __int64;
static auto start_time = std::chrono::system_clock::now();
//static auto start_test = std::chrono::system_clock::now();

/** 时间结构体
 *	ms_pos 毫秒
 *	s_pos 秒
 *	min_pos 分钟
 *	hour_pos 小时
 *	day_pos 天
 */
typedef struct TimePos_
{
	int ms_pos;
	int s_pos;
	int min_pos;
	int hour_pos;
	int day_pos;
}TimePos;

/** 事件信息
 *  interval	时间间隔
 *  time_pos	时间轮槽
 *  address	客户端地址
 *  sockfd	客户端句柄
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
	/** 初始化时间轮
     *	step 以毫秒为单位，表示定时器最小时间粒度
	 *	max_time 表示定时器所能接受的最大天数间隔
	 */
	int initTimerWheel(int step,int max_time);
	
	int generateTimerID();
	
	/** 添加定时任务
     *	sockfd 客户端套接字
	 *	interval 定时间隔 :ms
	 *	call_back 定时回调执行函数
	 */
	int addTimer(int sockfd, __int64 interval, std::function<void(int, char*)>& call_back);
	
private:
	/** 初始化结构体
	 */
	void init();
	
	/** 时间轮循环
	 */
	int doLoop();
	
	/** 插入事件
     *	diff_ms 定时时间
	 *	einfo 事件
	 */
	int insertTimer(EventInfo& einfo);
	
	/** 获取事件在时间轮上的位置
	 *	time_pos 时间轮
	 */
	int getNextTrigerPos(__int64 interval,TimePos& time_pos);

	int getTimerTrigerPos(EventInfo& einfo,TimePos& time_pos);
	
	/** 获取时间轮时间
	 */
	__int64 getMS(TimePos& time_pos);
	
	/** 处理时间轮槽上的事件
	 *	事件列表
	 */
	int dealTimeWheeling(std::list<EventInfo> leinfo);
	
	/** 时间轮睡眠时间
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

