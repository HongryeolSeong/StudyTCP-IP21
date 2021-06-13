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
[server.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_server.c) [server.c](https://github.com/HongryeolSeong/StudyTCP-IP21/blob/main/0611/hello_client.c)

<br>
<br>
