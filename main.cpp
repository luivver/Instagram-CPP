#include "instagram.h"

int main(){
    //membuat list parent
    listParent LP;
    createListParent(LP);

    //membuat list child
    listChild LC;
    createListChild(LC);

    adrP newP;
    //menu
    int input = menu();
    while (input == 1 || input == 2){
        if (input == 2){
            string newAcc, newVerified;
            cout << endl;
            cout << "Create new account" << endl;
            cout << "Input username: ";
            cin >> newAcc;
            cout << "Do you want your account verified? (Y/N): ";
            cin >> newVerified;

            adrP doubleAcc;
            if (newVerified == "Y" || newVerified == "N"){
                if (newVerified == "Y"){
                    newP = newParent(newAcc, true);
                } else {
                    newP = newParent(newAcc, false);
                }
                if (first(LP) == NULL){
                    insertParent(LP, newP);
                    cout << "This username is available" << endl;
                    cout << "Welcome to Instagram" << endl;
                } else {
                    findParent(LP, newAcc, doubleAcc);
                    //cout << doubleAcc << endl;
                    if (doubleAcc != NULL){
                        cout << "This username is already registered" << endl;
                    } else {
                        insertParent(LP, newP);
                        cout << "This username is available" << endl;
                        cout << "Welcome to Instagram" << endl;
                    }
                }
            } else {
                cout << "Invalid input" << endl;
            }
        } else {
            string inputAcc;
            cout << endl << "Input username: ";
            cin >> inputAcc;
            adrP foundP;
            findParent(LP, inputAcc, foundP);
            //cout << foundP << endl;
            if (first(LP) == NULL){
                cout << "User not found, please register first" << endl;
            } else if (foundP == NULL){
                cout << "User not found, please register first" << endl;
            } else {
                int num = menuLogin(inputAcc);
                while (foundP != NULL && (num >= 1 && num <= 7)) {
                    if (num == 1){
                        cout << "Type the username that you want to follow: ";
                        string follow_uname;
                        cin >> follow_uname;
                        follow(LP, LC, follow_uname, inputAcc);
                    } else if (num == 2) {
                        cout << "Type the username you want to unfollow: ";
                        string unfollow_name;
                        cin >> unfollow_name;
                        unfollow(LP, LC, unfollow_name, inputAcc);
                    } else if (num == 3){
                        cout << "List of account and its followers: " << endl;
                        showAccountAndFollowers(LP);
                    } else if (num == 4){
                        int sumFollow = sumFollowing(LP, inputAcc);
                        //cout << sumFollow;
                        //cout << "tes" << endl;
                        if (sumFollow == 0){
                            cout << "You are following no one" << endl;
                        } else {
                            cout << "You have followed " << sumFollow << " account" << endl;
                            showFollowing(LP, inputAcc);
                        }
                    } else if (num == 5){
                        cout << "List account: " << endl;
                        showAllAccount(LP);
                    } else if (num == 6){
                        adrP deletedAcc;
                        deleteAccount(LP, deletedAcc, inputAcc);
                        break;
                    } else {
                        string search_user;
                        cout << "Search username: ";
                        cin >> search_user;
                        adrP foundP;
                        findParent(LP, search_user, foundP);
                        if (foundP != NULL){
                            if (info(foundP).verified == true){
                                cout << info(foundP).acc << " - " << "verified" << endl;
                            } else {
                                cout << info(foundP).acc << " - " << "not verified" << endl;
                            }
                        } else {
                            cout << "Username not found" << endl;
                        }
                    }
                    num = menuLogin(inputAcc);
                }
            }
        }
        input = menu();
    }
    cout << "Thank you for using instagram" << endl;

    return 0;
}
