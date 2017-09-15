//
// Created by jbernard on 9/14/17.
//

int getVirusStatusFromVirusSensor(int isGood){
    if (isGood == 1){
        return 5;
    }
    if (isGood == 0){
        return 10;
    }
    return 0;
}