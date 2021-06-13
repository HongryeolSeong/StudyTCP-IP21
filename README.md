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
   
소켓은 서버(리스닝)소켓 + 클라이언트 소켓으로 나누어진다.   
1. 서버 소켓의 흐름   
socket(): 소켓 생성 -> bind(): 소켓에 IP와 포트 부여 -> listen(): 연결요청 가능한 소켓으로 설정 -> accept(): 연결요청에 대한 수락   
2. 클라이언트 소켓의 흐름   
socket() -> connect(): 서버 소켓으로의 연결 요청   
<br>

해당 코드   
[server.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_server.c)   [client.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_client.c)

<br>
<br>

## 리눅스 기반 실행🎯
VMware + Ubuntu를 설치하여 환경 구성.   

리눅스에서의 소켓 조작은 파일 조작과 동일하게 간주된다.   
사용자가 소켓(or 파일) 생성 -> OS는 해당 소켓에 파일 디스크립터 부여   
파일 디스크립터 : 파일 또는 소켓에 부여된 정수(0,1,2번은 표준에 할당되어있다.)   

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
