#ifndef ACTIVEACCOUNTS_H
#define ACTIVEACCOUNTS_H


class ActiveAccounts
{
public:
    ActiveAccounts(int ID,int accnt);

    int getAccount() const;
    int getEventID() const;

protected:
    int account;
    int eventID;

};

#endif // ACTIVEACCOUNTS_H
