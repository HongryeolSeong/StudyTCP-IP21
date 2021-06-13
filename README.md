# StudyTCP-IP21
PKNU IoT 개발자 과정   
TCP/IP Stucdy Repository
<br>
<br>

## 네트워크 프로그래밍이란🎯
네트워크로 연결된 두 컴퓨터가 데이터를 주고받을 수 있도록 하는 것.   
HW 연결 + SW 연결이 필요하다.   
1. HW부분은 이미 국내 네트워크가 잘 활성화 되어 있으므로 신경 쓸 필요 없다.
2. SW부분은 운영체제에서 소켓을 제공하니 이것을 바탕으로 프로그래밍 할 것.   
   
##### 소켓은 서버(리스닝)소켓 + 클라이언트 소켓으로 나누어진다.   
1. 서버 소켓의 흐름   
socket(): 소켓 생성 -> bind(): 소켓에 IP와 포트 부여 -> listen(): 연결요청 가능한 소켓으로 설정 -> accept(): 연결요청에 대한 수락   
2. 클라이언트 소켓의 흐름   
socket() -> connect(): 서버 소켓으로의 연결 요청   
<br>

해당 코드🎮
[server.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_server.c)   [client.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_client.c)
<br>
<br>

## 리눅스 기반 실행🎯
VMware + Ubuntu를 설치하여 환경 구성.   

리눅스에서의 소켓 조작은 파일 조작과 동일하게 간주된다.   
사용자가 소켓(or 파일) 생성 -> OS는 해당 소켓에 파일 디스크립터 부여   
파일 디스크립터 : 파일 또는 소켓에 부여된 정수(0,1,2번은 표준에 할당되어있다.)   

##### 파일에 데이터 쓰기   

1. 파일 열기   
```C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
         //path: 파일 이름 문자열의 주소 값
int open(const char* path, int flag);
                     //flag: 파일의 오픈 모드 정보
```
<br>

2. 파일 닫기   
```C
#include <unistd.h>
         //fd: 소켓의 파일 디스크립터
int close(int fd);
```   
<br>

3. 파일에 데이터 쓰기   
```C
#incldue <unistd.h>
//signed int              //buf: 전송할 데이터가 저장된 버퍼의 주소 값
ssize_t write(int fd, const void* buf, size_t nbytes);
                                       //nbytes: 전송할 데이터의 바이트 수
```   

해당 코드🎮
[low_open.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/low_open.c)   
![결과9](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")   
<br>

##### 파일에 저장된 데이터 읽기

```C
#include <unistd.h>

ssize_t read(int fd, void* buf, size_t nbytes);
```   

해당 코드🎮
[low_read.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/low_read.c)   
![결과9](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")   
<br>

##### 파일 디스크립터와 소켓   
해당 코드🎮
[fd_seri.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/fd_seri.c)   
![결과9](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")   
파일 디스크립터는 0,1,2 이후의 숫자로 순서대로 넘버링 되는 것을 볼 수 있다.   
<br>
<br>

## 윈도우 기반 실행🎯
상당수의 서버가 리눅스 기반으로 개발되는 동시에   
클아이언트 프로그램의 경우 윈도우 기반 개발이 대부분이다.   
<br>

##### window 기반 개발시
1. 리눅스 기반 소켓 함수와 차이(함수 인수의 자료형)가 조금 있음을 알 것
2. winsock2.h 헤더 파일을 포함 할 것
3. ws2_32.lib 라이브러리를 링크시킬 것
4. winsock의 초기화가 필요하다   
<br>

##### winsock의 초기화
윈속 프로그래밍시 반드시 WSAStartup()을 통해 프로그램 요구 윈도우 소켓의 버전을 알리고, 해당 버전 지원 라이브러리의 초기화를 진행해야 한다.   
```C
#include <winsock2.h>
         //wVersionRequested: 윈속 버전 정보
int WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
                                    //lpWSAData: WSADATA라는 구조체 변수의 주소 값
```   
<br>

##### 리눅스 서버 + 윈도우 클라이언트
해당 코드🎮
[server.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_server.c)  [client_win.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_client_win.c)   
![결과9](https://github.com/HongryeolSeong/StudyC21/blob/main/img/res1.png "2차원배열")   
리눅스 서버는 우분투 OS에서, 윈도우 클라이언트는 윈도우 OS cmd를 통해 구동했다.
<br>
<br>

## 프로토콜🎯
서로 데이터를 주고 받기(대화) 위해서 정희해 놓은 규약/약속   
<br>
```C
#include <sys/socket.h>
      //1. 프로토콜의 체계        //3. 사용할 프로토콜
int socket(int domain, int type, int protocol);
                  //2. 소켓의 타입
```   

##### 프로토콜의 체계
PF_INET(IPv4), PF_INET6(IPv6), PF_LOCAL(로컬), PF_PACKET(Low Level 소켓), PF_IPX(IPX 노벨)   
등이 있지만 보편적으로 사용되는 PF_INET를 활용하여 학습한다.
<br>

##### 소켓의 타입
