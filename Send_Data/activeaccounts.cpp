#include "activeaccounts.h"

ActiveAccounts::ActiveAccounts(int ID,int accnt)
{
    eventID=ID;
    account=accnt;

}

int ActiveAccounts::getAccount() const
{
    return account;
}

int ActiveAccounts::getEventID() const
{
    return eventID;
}
