#include "instagram.h"

void createListParent(listParent &LP){
    first(LP) = NULL;
}

void createListChild(listChild &LC){
    first(LC) = NULL;
}

adrP newParent(string acc, bool verified){
    adrP newP = new elementParent;

    info(newP).acc = acc;
    info(newP).verified = verified;
    child(newP) = NULL;
    next(newP) = NULL;

    return newP;
}

adrC newChild(string acc, bool verified){
    adrC newfoll = new elementChild;

    info(newfoll).acc = acc;
    info(newfoll).verified = verified;
    next(newfoll) = NULL;

    return newfoll;
}

void insertParent(listParent &LP, adrP newP){
    if (first(LP) == NULL){
        first(LP) = newP;
    } else {
        next(newP) = first(LP);
        first(LP) = newP;
    }
}

void insertChild(listChild &LC, adrC newC){
    if (first(LC) == NULL){
        first(LC) = newC;
        next(newC) = first(LC);
    } else {
        adrC currC = first(LC);
        while (next(currC) != first(LC)){
            currC = next(currC);
        }
        next(currC) = newC;
        next(newC) = first(LC);
    }
}

void findParent(listParent LP, string acc, adrP &foundP){
    adrP curr = first(LP);
    if (first(LP) == NULL){
        foundP = NULL;
    } else {
        while (info(curr).acc != acc && first(LP)!= NULL){
            curr = next(curr);
            if (curr == NULL){
                foundP = curr;
                break;
            }
        }
        foundP = curr;
    }
}

void findChild(listChild LC, string acc, adrC &foundC){
    adrC temp = first(LC);
    if (next(temp) == first(LC)){
        if (info(temp).acc != acc){
            foundC = NULL;
        }
    } else {
        while (info(temp).acc != acc && next(temp) != first(LC)){
            temp = next(temp);
        }
        if (info(temp).acc == acc) {
            foundC = temp;
        } else {
            foundC = NULL;
        }
    }
}

void deleteParent(listParent &LP, string acc, adrP &deletedP){
    adrP foundP;
    deletedP = NULL;
    if (first(LP) == NULL){
        cout << "Data Empty" << endl;
    } else {
        findParent(LP, acc, foundP);
        if (foundP == NULL){
            cout << "Account Not Found" << endl;
        } else if (foundP == first(LP)){ //DELETE FIRST
            deletedP = foundP;
            first(LP) = next(first(LP));
            next(deletedP) = NULL;
        } else if (next(foundP) == NULL){ //DELETE LAST
            deletedP = foundP;
            adrP curr = first(LP);
            while (next(curr) != foundP){
                curr = next(curr);
            }
            next(curr) = NULL;
        } else { //DELETE AFTER
            deletedP = foundP;
            adrP prec = first(LP);
            while (next(prec) != foundP){
                prec = next(prec);
            }
            next(prec) = next(foundP);
            next(foundP) = NULL;
        }
    }
}

void deleteChild(listChild &LC, string acc, adrC &deletedC){
    if (first(LC) == NULL){
        cout << "You have no followers" << endl;
    } else {
        adrC foundC;
        findChild(LC, acc, foundC);
        deletedC = foundC;
        //cout << "DELETED: " << info(deletedC).acc << endl;
        if (next(first(LC)) == first(LC)){ //hanya ada 1 element
            first(LC) = NULL;
        } else if (foundC == first(LC)){ //DELETE FIRST
            adrC curr = first(LC);
            while (next(curr) != first(LC)){
                curr = next(curr);
            }
            first(LC) = next(first(LC));
            next(curr) = first(LC);
            next(foundC) = NULL;
        } else if (next(foundC) == first(LC)){ //DELETE LAST
            adrC currC = first(LC);
            while (next(next(currC)) != first(LC)){
                currC = next(currC);
            }
            next(currC) = first(LC);
            next(foundC) = NULL;
        } else { //DELETE AFTER
            adrC prec = first(LC);
            while (next(prec) != foundC){
                prec = next(prec);
            }
            next(prec) = next(foundC);
            next(foundC) = NULL;
        }
    }
}

int sumFollowers(listParent LP, string acc){
    int sum = 0;
    adrP foundP;
    findParent(LP, acc, foundP);
    adrC currC = child(foundP);
    if (child(foundP) == NULL){
        sum = 0;
    } else {
        while (next(currC) != child(foundP)){
            sum += 1;
            currC = next(currC);
        }
        sum += 1;
    }

    return sum;
}

void showAllAccount(listParent LP){
    int num = 1;
    for (adrP currP = first(LP); currP != NULL; currP = next(currP)){
        if (info(currP).verified == true){
            cout << num << ". " << info(currP).acc << " - " << "verified" << endl;
        } else {
            cout << num << ". " << info(currP).acc << " - " << "not verified" << endl;
        }
        num++;
    }
}

void showAccountAndFollowers(listParent LP){
    adrP main = first(LP);
    if (first(LP) == NULL){
        cout << "No account is listed" << endl;
    } else {
        while (main != NULL){
            cout << endl;
            cout << "Followers list of @" << info(main).acc << endl;
            cout << "You have " << sumFollowers(LP, info(main).acc) << " followers" << endl;
            adrC currC = child(main);
            if (currC != NULL){
                while (next(currC) != child(main)){
                    if (info(currC).verified == true){
                        cout << info(currC).acc << " - " << "verified" << endl;
                    } else {
                        cout << info(currC).acc << " - " << "not verified" << endl;
                    }
                    currC = next(currC);
                }
                if (info(currC).verified == true){
                    cout << info(currC).acc << " - " << "verified" << endl;
                } else {
                    cout << info(currC).acc << " - " << "not verified" << endl;
                }
            }
            main = next(main);
        }
    }
}

void follow(listParent LP, listChild &LC, string accFollow, string accUser){
    adrP foundP;
    adrP foundC;
    findParent(LP, accFollow, foundP);
    findParent(LP, accUser, foundC);

    adrC newFollower = newChild(info(foundC).acc, info(foundC).verified);
    if (foundC != NULL && foundP != NULL){
        if (accFollow == accUser) {
            cout << "You can't follow yourself" << endl;
        } else if (child(foundP) == NULL){
            child(foundP) = newFollower;
            first(LC) = child(foundP);
            next(first(LC)) = first(LC);
        } else {
            first(LC) = child(foundP);
            adrC already_follow;
            //cout << "tes" << endl;
            findChild(LC, accUser, already_follow);
            //cout << info(child(foundP)).acc << endl;
            //cout << already_follow << endl;
            if (already_follow != NULL){
                cout << "You already followed this account" << endl;
            } else {
                first(LC) = child(foundP);
                insertChild(LC, newFollower);
            }
        }
    } else {
        cout << "Username not found" << endl;
    }
}

void unfollow(listParent LP, listChild &LC, string accUnfollow, string accUser){
    adrP foundP;
    adrC foundC, whoUnfoll;
    findParent(LP, accUnfollow, foundP);

    if (foundP != NULL){
        first(LC) = child(foundP);
        findChild(LC, accUser, foundC);
        if (foundC != NULL){
            if (next(first(LC)) == first(LC)){
                child(foundP) = NULL;
                first(LC) = NULL;
            } else {
                deleteChild(LC, accUser, whoUnfoll);
                //cout << whoUnfoll << endl;
                cout << "You have unfollowed " << accUnfollow << endl;
            }
        } else {
            cout << "You don't follow this account" << endl;
        }
    }
}

int menu(){
    cout << endl;
    cout << "============= INSTAGRAM =============" << endl;
    cout << "1. Login" << endl;
    cout << "2. Don't have an account? Sign Up" << endl;
    cout << "0. Exit" << endl;

    cout << "Select Menu : ";
    int input;
    cin >> input;

    return input;
}

int menuLogin(string acc){
    cout << endl;
    cout << "=====================================" << endl;
    cout << "Welcome back to Instagram, " << acc << endl;
    cout << "Choose 1 to follow" << endl;
    cout << "Choose 2 to unfollow" << endl;
    cout << "Choose 3 to list of followers" << endl;
    cout << "Choose 4 to list of followings" << endl;
    cout << "Choose 5 to show all Instagram users" << endl;
    cout << "Choose 6 to delete your account" << endl;
    cout << "Choose 7 to search account" << endl;
    cout << "Choose 8 to logout of Instagram" << endl;
    cout << "Choose number : ";
    int num;
    cin >> num;
    cout << "=====================================" << endl;

    return num;
}

void printList(listParent LP, listChild LC, string acc){
    adrP foundP;
    findParent(LP, acc, foundP);
    cout << info(child(foundP)).acc << endl;
}

void deleteAccount(listParent &LP, adrP &deletedAccount, string acc){
    deleteParent(LP, acc, deletedAccount);
    /*if (deletedAccount != NULL){
        cout << "Your account has been deleted" << endl;
    }*/

    //menghapus child di tiap parent
    adrP currP = first(LP);
    listChild LC;
    while (currP != NULL){
        first(LC) = child(currP);
        if (first(LC) == NULL){
            currP = next(currP);
        } else {
            adrC foundChild, deletedC;
            findChild(LC, acc, foundChild);
            //cout << foundChild << endl;
            if (foundChild != NULL){
                deleteChild(LC, acc, deletedC);
            }
            currP = next(currP);
        }
    }
    cout << "Your account has been deleted" << endl;

}

void showFollowing(listParent LP, string acc){
    listChild LC;
    adrP currP = first(LP);
    while (currP != NULL){
        first(LC) = child(currP);
        if (first(LC) == NULL || info(currP).acc == acc){
            currP = next(currP);
        } else {
            adrC foundChild;
            findChild(LC, acc, foundChild);
            if (foundChild != NULL){
                if (info(currP).verified == true){
                    cout << info(currP).acc << " - " << "verified" << endl;
                } else {
                    cout << info(currP).acc << " - " << "not verified" << endl;
                }
            }
            currP = next(currP);
        }
    }
}

int sumFollowing(listParent LP, string acc){
    int sum = 0;
    listChild LC;
    adrP currP = first(LP);
    while (currP != NULL){
        first(LC) = child(currP);
        if (first(LC) == NULL || info(currP).acc == acc){
            currP = next(currP);
        } else {
            adrC foundChild;
            findChild(LC, acc, foundChild);
            if (foundChild != NULL){
                sum += 1;
            }
            currP = next(currP);
        }
    }
    return sum;
}




