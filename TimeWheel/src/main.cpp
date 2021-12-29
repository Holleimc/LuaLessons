/*
#ifdef _WIN32
#	include <winsock2.h>
#	include <ws2tcpip.h>
#	include <windows.h>
#	include <DbgHelp.h>
#	include <intsafe.h>
#	include <io.h>
#	include <process.h>
#	include <sys/timeb.h>
#	include <direct.h>
#	pragma comment(lib, "WS2_32")  // ���ӵ�WS2_32.lib
#else   
//��Щ��Linux��Darwin���õ�ͷ�ļ�
#	include <arpa/inet.h>
#	include <ctype.h>
#	include <dirent.h>
#	include <errno.h>
#	include <execinfo.h>
#	include <limits.h>
#	include <netdb.h>
#	include <netinet/in.h>
#	include <netinet/tcp.h>
#	include <pthread.h>
#	include <sched.h>
#	include <signal.h>
#	include <stdarg.h>
#	include <sys/types.h>
#	include <sys/socket.h>
#	include <sys/ioctl.h>
#	include <sys/time.h>
#	include <sys/wait.h>
#	include <sys/poll.h>
#	include <unistd.h>

#	ifdef __LINUX__
#		include <sys/epoll.h>
#	endif

#	ifdef DARWIN
#	endif

#endif
*/
#include <thread>
#include "../include/TimeWheel.h"
//#include "server.h"
using namespace std;

static auto start_test = std::chrono::system_clock::now();
static void sendMsg(int sockfd, char* buf)
{
	//char buf1[BUFFER_SIZE] = "ok";
	//if (send(sockfd, buf, sizeof(buf)-1, 0) < 0)
	if(0)		
	{
		perror("error");

		//auto time2 = std::chrono::system_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now() - start_test).count()<<std::endl;
		//exit(-1);
	}
	// std::cout << "Spend: " << std::chrono::duration_cast<std::chrono::milliseconds>
	// 	(std::chrono::system_clock::now() - start_test).count()<< "ms!" << std::endl;
	cout << "is time!" << endl;
}


int main()
{	
	std::function<void(int, char*)> sdMsg = std::bind(&sendMsg, std::placeholders::_1, std::placeholders::_2);

	TimeWheel time_wheel;
	time_wheel.initTimerWheel(1, 5);
  //	__int64 interval = 2000+1000;
	//int sockfd = 0;
	//time_wheel.addTimer(sockfd, interval, sdMsg);
	int nloop = 5;
	start_test = std::chrono::system_clock::now();
	time_wheel.addTimer(nloop, 5000, sdMsg);
	while(1)
	{
		this_thread::sleep_for(chrono::milliseconds(8000));
		nloop++;
		start_test = std::chrono::system_clock::now();
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
		time_wheel.addTimer(nloop, 5000, sdMsg);
		time_wheel.addTimer(nloop, 6000, sdMsg);
		time_wheel.addTimer(nloop, 7000, sdMsg);
		time_wheel.addTimer(nloop, 8000, sdMsg);
		time_wheel.addTimer(nloop, 9000, sdMsg);
		time_wheel.addTimer(nloop, 10000, sdMsg);
		time_wheel.addTimer(nloop, 11000, sdMsg);
	}

	return 0;
}
