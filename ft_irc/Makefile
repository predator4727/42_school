CXX = g++ -g3 -pthread
CXXFLAGS = -Wall -Wextra -Werror
NAME = ircserv
SRC_DIR = source
OBJ_DIR = obj
INCLUDE = -I${SRC_DIR}
SRC_FILES = main.cpp \
            IRCServer/IRCServer.cpp \
            Channel/Channel.cpp \
            ClientConnection/ClientConnection.cpp \
            Commands/Command/Command.cpp \
            Commands/PassCommand/PassCommand.cpp \
            Commands/JoinCommand/JoinCommand.cpp \
            Commands/NickCommand/NickCommand.cpp \
			Commands/UserCommand/UserCommand.cpp \
            Commands/OperatorCommands/OperatorCommands.cpp \
            Commands/PartCommand/PartCommand.cpp \
            Commands/PrivmsgCommand/PrivmsgCommand.cpp \
            Commands/NoticeCommand/NoticeCommand.cpp \
            Commands/QuitCommand/QuitCommand.cpp \
            MessageToolkit/MessageToolkit.cpp \
            User/User.cpp

OBJ_FILES = ${SRC_FILES:%.cpp=${OBJ_DIR}/%.o}

all: ${NAME}

${NAME}: ${OBJ_FILES}
	${CXX} ${CXXFLAGS} ${INCLUDE} $^ -o $@ -lpthread

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	@mkdir -p ${@D}
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@

clean:
	rm -rf ${OBJ_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
