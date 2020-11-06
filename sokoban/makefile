CC = g++
CFLAGS = -std=c++14
TARGET = sokoban
SOURCES = Main.cpp \
		managers/GameManager.cpp \
		managers/ObjectManager.cpp \
		managers/SceneManager.cpp \
		objects/Box.cpp \
		objects/Goal.cpp \
		objects/Object.cpp \
		objects/Road.cpp \
		objects/User.cpp \
		objects/Wall.cpp \
		panes/GamePane.cpp \
		panes/InfoPane.cpp \
		panes/MenuPane.cpp \
		panes/GuidePane.cpp \
		panes/Pane.cpp \
		scenes/GameScene.cpp \
		scenes/StartScene.cpp\
		scenes/RankingScene.cpp\
		utils/FileManager.cpp\
		utils/Ranking.cpp \
	

LDFLAGS = -lncurses

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
