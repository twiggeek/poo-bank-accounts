#include "AccountFactory.hh"

AccountFactory::AccountFactory() {
  _listAccountTypes[Account::NORMAL] = &AccountFactory::createAccountNormal;
  _listAccountTypes[Account::CHILD]  = &AccountFactory::createAccountChild;
  _listAccountTypes[Account::OLD]    = &AccountFactory::createAccountOld;
}

AccountFactory::~AccountFactory() {}

Account *AccountFactory::createAccountNormal(User *user, Id *id, double balance, Account *tutor) {
  return new AccountNormal(user, id, balance, tutor);
}

Account *AccountFactory::createAccountChild(User *user, Id *id, double balance, Account *tutor) {
  return new AccountChild(user, id, balance, tutor);
}

Account *AccountFactory::createAccountOld(User *user, Id *id, double balance, Account *tutor) {
  return new AccountOld(user, id, balance, tutor);
}

Account *AccountFactory::createAccount(Account::AccountType type, User *user, Id *id, double balance, Account *tutor) {
  return (this->*_listAccountTypes[type])(user, id, balance, tutor);
}
