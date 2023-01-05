#ifndef INSTAGRAM_H_INCLUDED
#define INSTAGRAM_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define child(p) (p)->child
#define first(L) ((L).first)

struct account {
    string acc;
    bool verified;
};

typedef account infotype;
typedef struct elementParent *adrP;
typedef struct elementChild *adrC;

struct elementParent {
    infotype info;
    adrC child;
    adrP next;
};

struct elementChild {
    infotype info;
    adrC next;
};

struct listParent {
    adrP first;
};

struct listChild {
    adrC first;
};

void createListParent(listParent &LP);
void createListChild(listChild &LC);
adrP newParent(string acc, bool verified);
adrC newChild(string acc, bool verified);
void insertParent(listParent &LP, adrP newP);
void insertChild(listChild &LC, adrC newC);
void findParent(listParent LP, string acc, adrP &foundP);
void findChild(listChild LC, string acc, adrC &foundC);
void deleteParent(listParent &LP, string acc, adrP &deletedP);
void deleteChild(listChild &LC, string acc, adrC &deletedC);
int sumFollowers(listParent LP, string acc);
void showAccountAndFollowers(listParent LP);
void showAllAccount(listParent LP);
void follow(listParent LP, listChild &LC, string accFollow, string accUser);
void unfollow(listParent LP, listChild &LC, string accUnfollow, string accUser);
int menu();
int menuLogin(string acc);
void printList(listParent LP, listChild LC, string acc);
void deleteAccount(listParent &LP, adrP &deletedAccount, string acc);
void showFollowing(listParent LP, string acc);
int sumFollowing(listParent LP, string acc);


#endif // INSTAGRAM_H_INCLUDED
