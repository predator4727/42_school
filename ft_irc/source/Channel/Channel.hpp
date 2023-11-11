#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <string>
# include <map>
# include <vector>
# include "User/User.hpp"

class IRCServer;

class Channel
{
    private:
        const std::string			_name;
        IRCServer&					_ircServer;
        std::map<std::string, bool>	_users; // Single data structure to store users and their operator status
		std::string					_topic;
		bool						_isTopicLocked;
		bool						_isInviteOnly;
		unsigned int				_maxUserCount;
		std::string					_password;
		std::vector<std::string>	_invitedUsers;

    public:
        Channel(IRCServer& ircServer, const std::string name);
        ~Channel();

        std::string getName() const;

        void addUser(std::string user, bool isOperator = false, std::string password = ""); // Added an optional isOperator parameter
        void removeUser(std::string user);
        bool hasUser(std::string user) const;

		bool isOperator(std::string user) const; // New method to check operator status
        void setOperator(std::string sourceUser, std::string targetUser, bool isOperator); // New method to set operator status

		bool isInviteOnly() const;
		void setIsInviteOnly(std::string sourceUser, bool isInviteOnly);

		bool isInvited(std::string user) const;
		void inviteUser(std::string sourceUser, std::string targetUser);

		bool isTopicLocked() const;
		void setIsTopicLocked(std::string sourceUser, bool isTopicLocked);

		std::string getTopic() const;
		void setTopic(std::string sourceUser, const std::string &topic);

		std::string getPassword() const;
		void setPassword(std::string sourceUser, const std::string &password);

		unsigned int getMaxUserCount() const;
		void setMaxUserCount(std::string sourceUser, unsigned int maxUserCount);

		unsigned int getUserCount() const;

        void broadcastMessage(const std::string &message, std::string sender = NULL);

		void kickUser(std::string user, std::string sender, const std::string &reason);
};


#endif
