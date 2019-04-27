# accounting-system (Idea 4)
ENGG1340 Group 3 (Tam Fong Ching Herbert 3035554828, Park Sangwon 3035556060)

## Problem Statement
As university students work part time or get allowance, we know first hand the problems of organizing money. We will be building a user-friendly lightweight accounting system catered towards students like us.

## Problem Setting
Young people may find it difficult to transition into financial indepedence, yet building a habit to monitor their own spending may prove to be a daunting task, especially when many existing finance managers are complicated and inconvenient to use on a day-to-day basis. This has caused their inability to help motivate students into properly organizing their money. Our simple yet efficient accounting system will help university students track their money in an uncomplicated manner. 

## Basic Features
### 1. Add records of income and expenses
Students are able to easily add how much money they gained and how much money they used. Income and expenses will be updated in the database.
### 2. See information about income and expense
Users are able to view different information about their income and expenses such as amount, date, types of income or expense (e.g. food, game, salary, etc.), account (e.g. cash, bank card, credit card, etc.).
### 3. Fully editable records
Users are able to view, edit or delete their financial records at anytime.
### 4. View categorized records
Users are able to sort and filter their records by date, type, and account when necessesary.
### 5. Detailed statistical reports
Users have access to a wide range of statistical reports (e.g. monthly income and expenses, percentage of food expenses, etc.) that reflects their financial status.
### 6. Budget setting
The system also allows users to set a budget. And when expenses reach the budget, there is an alarm system in place to remind the user.

## Additional Features
### 1. Statistical graphs
One of the additional features is a new function which helps users visualize their spendings and savings. Through the use of graphs, we remind users of their progress towards their financial goals. Common statistics such as total income, total expenses, and total income + expenses are available and users can enter what type and what account to compare theses statistics to.
### 2. Budget planner
Expanding on a simple budget setting function, we created a planner where the user can choose how long they want to budget (e.g. 1 day for daily, 7 days for weekly, etc.). The accouting system tracks in real time how much money the user can spend until the budget time is over.
### 3. Simple user interface
Since it could be difficult for users to build a habit to track their spending, we hope to make doing so as easy as possible. We have created a simple user interface where users can give commands by entering a single letter. 
### 4. Interface configuration
Users can adjust the interface dimensions to view more records and have a wider and longer view.

## Getting started
In the terminal of your linux server, please clone the repository using:
```
git clone https://github.com/18sp01/accounting-system.git
```
After it is finished cloning, move into the master folder by entering:
```
cd accounting-system
```
To compile the program, type:
```
make
```
**_Note:_ Before executing the accounting system, please make sure your terminal window is greater than 99 in width and 14 in height for the best experience.**

When ready, to start the accounting system, type:
```
./eas
```

## Guide to the Easy Accounting System

Once you start, the main menu will look like this:

![Main Menu](https://i.imgur.com/R0a3IRT.png)

From here, you have 5 options to choose from: \[a\] to add record, \[v\] to view record, \[s\] to view user statistics, \[b\] to view the user's budget plan, and \[c\] to configure the accounting system interface.

### Add Record

Once you type "a" to add record, you will see a menu that looks like this:

![AddRecord_Menu](https://i.imgur.com/UKjOOkv.png)

Now, you can type, in order, the type of income/expense (food, game, etc.), the amount (negative for expenses), and type of account (cash, credit card, etc.).

![AddRecord](https://i.imgur.com/Zx7ax1F.png)

So now you've added your inheritance to the accounting system.

### View Record

Back at the main menu, type "v" to view your added record.

![ViewRecord1](https://i.imgur.com/kgsYo7V.png)

Eventually after a while of usage, it will become like this.

![ViewRecord2](https://i.imgur.com/LrGQu1y.png)

You can check other records by using the next and previous page functions. (Or head to configurations in the main menu to increase your interface size.)

### Sort Record

In the view records menu, the user has a variety of options to customize the user's data. One of them is sorting. Users can sort by amount, type of income/expense, account, and date.

Sorting by Most Recent (Default):

![SortRecord](https://i.imgur.com/QvHPSKn.png)

Sorting by Amount:

![SortAmount](https://i.imgur.com/QEbym9M.png)

Sorting by Type:

![SortType](https://i.imgur.com/e6Ba6f4.png)

Sorting by Account:

![SortAccount](https://i.imgur.com/KSHkVzP.png)

### Edit Record

Back at view record, the user can edit amount, type, and account of the data.

Because of inheritance tax law, your inheritance has decreased by 75%. We are going to edit the amount of the inheritance.

First we find the inheritance from the view records menu and type "e" to go to the edit records menu.

![EditRecords](https://i.imgur.com/dGaqLfD.png)

We choose amount:

![EditAmount](https://i.imgur.com/oeO2PLs.png)

and enter 50000 to change the data.

![EditAmount1](https://i.imgur.com/GDd2IpR.png)

### Filter Record

The user can filter the records to only see what the user want to see.

![FilterRecord](https://i.imgur.com/LVsxHmr.png)

Let's say we only want to see the data for my purchases of games.

We type "1" to choose type and write "Game" to find all the records that have the game type.

![FilterRecord1](https://i.imgur.com/y779Zbs.png)

From here, the user can further sort or edit the filtered data like in the view records menu.

### Statistics Report
