# Pushbox
- 상자를 밀어 지정된 장소에 옮기는 게임

### 과제 제출물
- source codes, make file, 프로젝트 보고서
- 1~3 단계를 구현한 내용을 보고서에 작성할 것

## windows 에서 ncurses사용하기!!

### pdcurses 받기!
[pdcurses3.4 다운로드](https://sourceforge.net/projects/pdcurses/files/pdcurses/3.4/)

![pdcurses3.4받기](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/pdcurses.png?raw=true)
이곳에서 pdcurs34.zip을 받아준뒤 압축을 푼다.

![pdcurses3.4 압축푼 결과](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/vcwin32.mak.png?raw=true)

### pdcurses 빌드하기!
![검색](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/visual.png?raw=true)

- vs 2013 버전일 때,
`[⌘]`키를 누르고 `visual` 이라고 검색합니다.
그러면 Visual Studio Tools폴더가 나타나게 됩니다.

더블 클릭후 들어가서 Developer `Command Prompt for VS2013` 을 더블클릭해서 실행시키면 됩니다.

- vs 2017 버전일 때,
`C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools` 경로로 이동합니다.
`LaunchDevCmd.bat`파일을 더블클릭해서 실행시키면 됩니다.

![command](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/command.png?raw=true)

그러면 프롬프트가 켜지는데, 다음 화면과 같이 명령어를 쳐주시면 빌드가 됩니다.

![command](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/nmake.png?raw=true)

```console
> cd {PDCURSES_WIN32_PATH}
> nmake -f vcwin32.mak WIDE=Y DLL=Y
```
### visual studio 프로젝트와 연동하기!

![command](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/property.png?raw=true)

우선 프로젝트 솔루션 탐색기에서 프로젝트에 마우스 커서를 올리고 우클릭후 속성을 클릭해서 프로젝트 설정에 들어갑니다.

![command](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/library_directory.png?raw=true)

이후 포함디렉토리에 pdcurses의 root 경로를 추가해주고
라이브러리 디렉토리에 pdcurses/win32 경로를 추가해줍니다.

![command](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/mTd.png?raw=true)
C/C++ > 코드생성 > 런타임 라이브러리 > 다중 스레드 디버그(/MTd)로 바꾸어줍니다.

![command](https://github.com/juheesvt/Pushbox/blob/master/kangjuhee/pdcurses.lib.png?raw=true)
링커 > 입력 > 추가종속성에 `pdcurses.lib` 문구를 추가해줍니다.

### 유의해야 할 점!

- linux 환경에선 include<ncurses.h> 였던것을 pdcurses를 사용하면 #include <curses.h>로 바꾸어야 합니다.
