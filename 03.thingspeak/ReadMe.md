## ThingSpeak Test
이 프로젝트에서는 ThingSpeak에 주기적으로 데이터를 전송하는 예제를 테스트합니다.

### 핵심 스펙
- WiFi 연결
- ThingSpeak에 랜덤 온도, 습도, 토양건조도 데이터 전송
  - 지금은 더미 데이터 전송

### 기타 스펙
- 연결 성공/실패시 효과음 재생
- WiFi의 ssid와 password는 git에 push되지 않는 ini 파일에 기록
- ThingSpeak API Key는 git에 push 되지 않는 ini 파일에 기록