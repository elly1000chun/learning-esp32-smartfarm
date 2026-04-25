# Learning ESP32

이 프로젝트에서는 ESP32에 대해 학습하고 스마트팜에 필요한 기초적인 구성요소를 구현합니다.

### 목표
 - 스마트팜에 필요한 기초 센싱/통신 구성요소 파악 및 구현
	 - Will do
		 - 온습도 측정
		 - 토양 습도 측정
		 - OLED Display에 정보 표시
		 - RTC 모듈을 사용해서 측정 시각 유닛별 자체 관리
		 - Wi-Fi를 통해 측정 정보를 로컬 서버 또는 클라우드 서버에 기록
	 - Nice to have
		 - 딥슬립 기능을 활용한 배터리 절약
		 - ESP32 유닛에 기본 유닛 정보(이름 등) 저장
		 - 시스템 로깅
		 - 기록된 정보 시계열 Visualize
	 - Will not do
		 - 조명 제어나 자동 물주기 (이 단계에서는 불필요)
     - MQTT 등 메시징 프로토콜 활용 (주기적으로 로깅하면 되므로 오버스펙)

### 개발 환경
이 프로젝트는  아래 환경으로 개발합니다.
 - ESP32
 - PlatformIO + VSCode
	 - 그 외 검토 대상: ESP-IDF, Arduino IDE
	 - 선택 이유
		 - 프로젝트 셋업 편의성, 라이브러리 관리 편의성
		 - 규모가 작은 프로젝트이며 ESP-IDF 수준의 고도의 제어는 필요하지 않음
		 - 개발자 본인의 VSCode 및 C++ 숙련도

### 사용 HW 및 모델명
|종류|모델명|
|--|--|
|ESP32 보드|WROOM32(CH340)|
|온습도 센서|AHT20|
|토양 습도 센서|Unknown|
|RTC 모듈|DS1302|
|OLED 0.96"|SSD1306|

### 하위 프로젝트 리스트
 1. Blink LED
 2. Simple Wi-Fi Test
 3. Using Thingspeak (Upload data to server)
 4. OLED Display
 5. Using RTC 
 6. Sensing(Temperature, Humidity, Soil Dryness)
 7. Full Integration

### 기타
#### 개발시 주의사항
- Security
  - Github에 올라가는 코드에는 외부 서비스의 API Key나 Wi-Fi Password가 직접 기재되어서는 안됨
- ...
