#include "Messenger.c"

/* Yes. */

int __DESSetNameOfFriend(Messenger *m, int friendnumber, uint8_t *name) {
    return setfriendname(m, friendnumber, name);
}

int __DESSetUserStatusOfFriend(Messenger *m, int friendnumber, uint8_t *status, uint16_t length) {
    return set_friend_statusmessage(m, friendnumber, status, length);
}

void __DESEnumerateFriendStatusesUsingBlock(Messenger *m, void(^block)(int idx, int status, char *stop)) {
    char stop = 0;
    for (int i = 0; i < m->numfriends; ++i) {
        block(i, m->friendlist[i].status, &stop);
        if (stop) break;
    }
}
