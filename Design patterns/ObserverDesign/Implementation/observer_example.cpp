#include <bits/stdc++.h>
#include <list>

using namespace std;

class ISubscriber {
public:
  virtual void notify(string mssg) = 0;
};

class User : public ISubscriber {
private:
  int id;

public:
  User(int id) { this->id = id; }
  void notify(string mssg) {
    cout << "user id : " << id << " Mssg : " << mssg << endl;
  }
};

class Group {
private:
  list<ISubscriber *> users;

public:
  void subscribe(ISubscriber *user) { users.push_back(user); }
  void unsubscribe(ISubscriber *user) { users.remove(user); }
  void notify(string mssg) {
    for (auto user : users) {
      user->notify(mssg);
    }
  }
};

int main() {

  Group *group = new Group;

  User *user1 = new User(1);
  User *user2 = new User(2);
  User *user3 = new User(3);

  // Add User 1, 2 and 3 to the group.
  group->subscribe(user1);
  group->subscribe(user2);
  group->subscribe(user3);

  // Whenever a message is sent all the user of that group has to receive
  group->notify("new mssg");

  // Unsubscribe User 1, from the group.
  group->unsubscribe(user1);
  group->notify("new new mssg");

  return 0;
}
