#include "../include/TimeWheel.h"
//#include <ctime>
using namespace std;

TimeWheel::TimeWheel()
{
	//memset(&_time_pos, 0, sizeof(_time_pos));

}

TimeWheel::~TimeWheel()
{
}

void TimeWheel::init()
{
	_pCallbackList = nullptr;
	_time_pos.day_pos = 0;_time_pos.hour_pos = 0;_time_pos.min_pos = 0;_time_pos.s_pos = 0;_time_pos.ms_pos = 0;
	_msCount = 0;
	_sCount = 0;
	_minCount = 0;
	_hourCount = 0;
	_dayCount = 0;
	_step_ms = 0;
	_timer_count = 0;

}

int TimeWheel::initTimerWheel(int step_ms, int max_time)
{
	init();
	if (1000 % step_ms != 0)
	{
		cout << "step is not property, should be divided by 1000" << endl;
		return -1;
	}
	int msNeedCount = 1000 / step_ms;
	int sNeedCount = 60;
	int minNeedCount = 60;
	int hourNeedCount = 24;
	int dayNeedCount = max_time;

	_pCallbackList = new std::list<EventInfo>[msNeedCount + sNeedCount + minNeedCount + hourNeedCount + dayNeedCount];
	_step_ms = step_ms;

	_msCount = msNeedCount;
	_sCount = sNeedCount;
	_minCount = minNeedCount;
	_hourCount = hourNeedCount;
	_dayCount = dayNeedCount;
	start_time = std::chrono::system_clock::now();
	std::thread th([&]{
		this->doLoop();
	});

	th.detach();
	return 0;
}
int TimeWheel::addTimer(int sockfd, __int64 interval, std::function<void(int, char*)>& call_back)
{
	if (interval < _step_ms || interval >= _step_ms * _msCount * _sCount * _minCount * _hourCount * _dayCount)
	{
		cout << "time interval is invalid" << endl;
		return -1;
	}

	int temp = interval % _step_ms;
	if(temp != 0)
	{
		interval += (_step_ms - temp);
	}
	//start_test = std::chrono::system_clock::now();

	std::unique_lock<std::mutex> lock(_mutex);

	EventInfo einfo = {0};
	einfo.interval = interval;
	einfo.call_back = call_back;
	einfo.time_pos.ms_pos = _time_pos.ms_pos;
	einfo.time_pos.s_pos = _time_pos.s_pos;
	einfo.time_pos.min_pos = _time_pos.min_pos;
	einfo.time_pos.hour_pos = _time_pos.hour_pos;
	einfo.time_pos.day_pos = _time_pos.day_pos;
	einfo.timer_id = generateTimerID();
	einfo.sockfd = sockfd;
	einfo.my_start_time = std::chrono::high_resolution_clock::now();
	lock.unlock();
	insertTimer(einfo);

	_timer_count++;

	cout << "insert timer success time_id: " << einfo.timer_id << endl;
	return einfo.timer_id;
}

int TimeWheel::generateTimerID()
{
	int x = rand() % 0xffffffff;
	int cur_time = time(nullptr);
	return x | cur_time | _timer_count;
}

int TimeWheel::insertTimer(EventInfo &einfo)
{
	TimePos time_pos = {0};
	getTimerTrigerPos(einfo, time_pos);
	if(time_pos.day_pos != _time_pos.day_pos)
	{
		_pCallbackList[_msCount + _sCount + _minCount + _hourCount + time_pos.day_pos].push_back(einfo);
		cout << "time pos: " << _msCount + _sCount + _minCount + time_pos.hour_pos << "    Timer ID: " << _pCallbackList[_msCount + _sCount + _minCount + _hourCount + time_pos.day_pos].begin()->timer_id << endl;
	}
	if(time_pos.hour_pos != _time_pos.hour_pos)
	{
		_pCallbackList[_msCount + _sCount + _minCount + time_pos.hour_pos].push_back(einfo);
		cout << "time pos: " << _msCount + _sCount + _minCount + time_pos.hour_pos << "    Timer ID: " << _pCallbackList[_msCount + _sCount + _minCount + time_pos.hour_pos].begin()->timer_id << endl;
	}
	if (time_pos.min_pos != _time_pos.min_pos)
	{
		_pCallbackList[_msCount + _sCount + time_pos.min_pos].push_back(einfo);
		cout << "time pos: " << _msCount + _sCount + time_pos.min_pos << "    Timer ID: " << _pCallbackList[_msCount + _sCount + time_pos.min_pos].begin()->timer_id << endl;
	}
	else if (time_pos.s_pos != _time_pos.s_pos)
	{
		_pCallbackList[_msCount + time_pos.s_pos].push_back(einfo);
		cout << "time pos: " << _msCount + time_pos.s_pos << "    Timer ID: " << _pCallbackList[_msCount + time_pos.s_pos].begin()->timer_id << endl;
	}
	else if (time_pos.ms_pos != _time_pos.ms_pos)
	{
		_pCallbackList[time_pos.ms_pos].push_back(einfo);
		cout << "time pos: " << time_pos.ms_pos << "    Timer ID: " << _pCallbackList[time_pos.ms_pos].begin()->timer_id << endl;
	}
	return 0;
}

int TimeWheel::getTimerTrigerPos(EventInfo& einfo, TimePos& time_pos)
{
	__int64 cur_ms = std::chrono::duration_cast<std::chrono::milliseconds>(einfo.my_start_time - start_time).count();
	__int64 future_ms = cur_ms + einfo.interval;
	
	time_pos.day_pos = (future_ms / (24 * 60 * 60 * 1000)) % _dayCount;
	time_pos.hour_pos = (future_ms % (24 * 60 * 60 * 1000)) / (60 * 60 * 1000);
	time_pos.min_pos = (future_ms % (60 * 60 * 1000)) / (60 * 1000);
	time_pos.s_pos = (future_ms % (60 * 1000)) / 1000;
	time_pos.ms_pos = (future_ms % 1000) / _step_ms;
	return 0;
}

int TimeWheel::getNextTrigerPos(__int64 interval, TimePos& time_pos)
{
	__int64 cur_ms = getMS(_time_pos);
	__int64 future_ms = cur_ms + interval;
	
	time_pos.day_pos = (future_ms / (24 * 60 * 60 * 1000)) % _dayCount;
	time_pos.hour_pos = (future_ms % (24 * 60 * 60 * 1000)) / (60 * 60 * 1000);
	time_pos.min_pos = (future_ms % (60 * 60 * 1000)) / (60 * 1000);
	time_pos.s_pos = (future_ms % (60 * 1000)) / 1000;
	time_pos.ms_pos = (future_ms % 1000) / _step_ms;
	return 0;
}

__int64 TimeWheel::getMS(TimePos& time_pos)
{
	return _step_ms * time_pos.ms_pos + time_pos.s_pos * 1000 + time_pos.min_pos * 60 * 1000 + time_pos.hour_pos * 60 * 60 * 1000 + time_pos.day_pos * 24 * 60 * 60 * 1000;
}


int TimeWheel::sleepTime(long interval, TimePos& time_pos)
{
	__int64 dead_line = getMS(time_pos) + interval;
	//auto time = std::chrono::system_clock::now();
	for(;;)
	{
		auto current_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - start_time).count();
		__int64 sleep_times = (dead_line * 1000000 - current_time + 999) / 1000;
		if(sleep_times <= 0)
		{
			return 0;
		}
		this_thread::sleep_for(chrono::nanoseconds(sleep_times));
	}
}

int TimeWheel::doLoop()
{
	_unit_ms = 1000000000;
	cout << "........starting loop........" << endl;
	static int nCount = 0;
	int msCount = 0;
  while (true)
	{
		//this_thread::sleep_for(chrono::nanoseconds(_unit_ms));
		/*
		__int64 dead_line = getMS(_time_pos) + _step_ms;
		auto current_time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now() - start_time).count();
		if(dead_line * 1000000 > current_time)
		{
			continue;
		}
		*/
		sleepTime(_step_ms, _time_pos);
		std::unique_lock<std::mutex> lock(_mutex);
		if(1000 == ++msCount)
		{
			msCount = 0;
			cout << ".........this is " << ++nCount <<"  loop........."<< endl;
		}
		TimePos pos = {0};
		TimePos last_pos = _time_pos;
		getNextTrigerPos(_step_ms, pos);
		_time_pos = pos;
		if(pos.day_pos != last_pos.day_pos)
		{
			if(_pCallbackList[_time_pos.day_pos + _hourCount + _minCount + _sCount + _msCount].size())
			{
				list<EventInfo>& leinfo = _pCallbackList[_time_pos.day_pos + _hourCount + _minCount + _sCount + _msCount];
				dealTimeWheeling(leinfo);
				leinfo.clear();
			}
		}

		else if(pos.hour_pos != last_pos.hour_pos)
		{
			if(_pCallbackList[_time_pos.hour_pos + _minCount + _sCount + _msCount].size())
			{
				list<EventInfo>& leinfo = _pCallbackList[_time_pos.hour_pos + _minCount + _sCount + _msCount];
				dealTimeWheeling(leinfo);
				leinfo.clear();
			}
		}

		else if (pos.min_pos != last_pos.min_pos)
		{
			if(_pCallbackList[_time_pos.min_pos + _sCount + _msCount].size())
			{
				list<EventInfo>& leinfo = _pCallbackList[_time_pos.min_pos + _sCount + _msCount];
				dealTimeWheeling(leinfo);
				leinfo.clear();
			}
		}
		else if (pos.s_pos != last_pos.s_pos)
		{
			if(_pCallbackList[_time_pos.s_pos + _msCount].size())
			{
				list<EventInfo>& leinfo = _pCallbackList[_time_pos.s_pos + _msCount];
				dealTimeWheeling(leinfo);
				leinfo.clear();
			}
		}
		else if (pos.ms_pos != last_pos.ms_pos)
		{
			if(_pCallbackList[_time_pos.ms_pos].size())
			{
				list<EventInfo>& leinfo = _pCallbackList[_time_pos.ms_pos];
				dealTimeWheeling(leinfo);
				leinfo.clear();
			}
		}
		else
		{
			cout << "error time not change" << endl;
			return -1;
		}
		lock.unlock();
	}
	return 0;
}

int TimeWheel::dealTimeWheeling(std::list<EventInfo> leinfo)
{
	for (auto item = leinfo.begin(); item != leinfo.end(); item++)
	{
		__int64 cur_ms = getMS(_time_pos);
		__int64 last_ms = getMS(item->time_pos);
		__int64 diff_ms = (cur_ms - last_ms + (_minCount + 1) * 60 * 1000) % ((_minCount + 1) * 60 * 1000);
		if (diff_ms == item->interval)
		{
			int sockfd = item->sockfd;
			char buf[BUFFER_SIZE] = "ok";
			
			item->call_back(sockfd, buf);
			std::cout << "Spend: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - item->my_start_time).count() << "ms!" << std::endl;
			--_timer_count;
		}
		else
		{
			insertTimer(*item);
		}
	}
	return 0;
}
