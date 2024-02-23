using System;
using System.Collections.Generic;

namespace Name
{
    class INotifyer
    {
        public void Notifity(decimal balance){}
    }

    class SMSLowBalanceNotifyer : INotifyer
    {
        private string _phone;
        private decimal _lowBalanceValue;
        public SMSLowBalanceNotifyer(string phone, decimal lowBalanceValue)
        {
            _phone = phone;
            _lowBalanceValue = lowBalanceValue;
        }

        public void Notifity(decimal balance)
        {
            Console.WriteLine($"SMSLowBalanceNotifyer ");
            if(balance < _lowBalanceValue){
                Console.Write(balance);
            }
        }
    }

    class EMailBalanceChangedNotifyer : INotifyer
    {
        private string _email;
        public EMailBalanceChangedNotifyer(string email)
        {
            _email = email;
        }

        public void Notifity(decimal balance)
        {
            Console.WriteLine("EMailBalanceChangedNotifyer ", balance);
        }
    }

    class Account
    {
        private decimal _balance;
        private List<INotifyer> _notifyers;
        public Account() 
        {
            _balance = 0;
            _notifyers = new List<INotifyer>();
        }

        public Account(int balance)
        {
            _balance = balance;
            _notifyers = new List<INotifyer>();
        }

        public void AddNotifyers(INotifyer notifyer) 
        {
            _notifyers.Add(notifyer);
        }

        private void Notification()
        {
            foreach (INotifyer notifyers in _notifyers)
            {
                notifyers.Notifity(_balance);
            }
        }

        public void ChangeBalance(decimal value)
        {
            _balance = value;
            Notification();
        }

        public decimal Get
        {
            get
            {
                return _balance;
            }
        }


    }

    class Progaram
    {
        static void Main(string[] args)
        {
            Account account_1 = new Account();
            Account account_2 = new Account(12344);
            SMSLowBalanceNotifyer sMSLowBalanceNotifyer = new SMSLowBalanceNotifyer("1234", 222);
            sMSLowBalanceNotifyer.Notifity(account_2.Get);
            EMailBalanceChangedNotifyer eMailBalanceChangedNotifyer = new EMailBalanceChangedNotifyer("ivan.var14@gmail.com");
            eMailBalanceChangedNotifyer.Notifity(account_2.Get);
        }
    }
}