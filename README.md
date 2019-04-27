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
**_Note:_ Before executing the accounting system, please make sure your terminal window is greater or equal to 113 in width and 14 in height for the best experience.**

When ready, to start the accounting system, type:
```
./eas
```

## Guide to the Easy Accounting System

Once you start, the main menu will look like this:

![Main Menu](https://i.imgur.com/R0a3IRT.png)

From here, you have 5 options to choose from: \[a\] to add record, \[v\] to view record, \[s\] to view user statistics, \[b\] to view the user's budget plan, and \[c\] to configure the accounting system interface.

### Add Record

![AddRecord_Menu](https://i.imgur.com/UKjOOkv.png)

Once you type "a" to add record, you will see a menu that looks like this.

![AddRecord](https://i.imgur.com/Zx7ax1F.png)

Now, you can type, in order, the type of income/expense (food, game, etc.), the amount (negative for expenses), and type of account (cash, credit card, etc.).

You've added your inheritance to the accounting system!

### View Record

![ViewRecord1](https://i.imgur.com/kgsYo7V.png)

Back at the main menu, type "v" to view your added record.

![ViewRecord2](https://i.imgur.com/LrGQu1y.png)

Eventually after a while of usage, it will become like this.

You can check other records by using the next and previous page functions. (Or head to configurations in the main menu to increase your interface size.)

### Sort Record

In the view records menu, the user has a variety of options to customize the user's data. One of them is sorting. Users can sort by amount, type of income/expense, account, and date.

![SortRecord](https://i.imgur.com/QvHPSKn.png)

Sorting by Most Recent (Default)

![SortAmount](https://i.imgur.com/QEbym9M.png)

Sorting by Amount

![SortType](https://i.imgur.com/e6Ba6f4.png)

Sorting by Type

![SortAccount](https://i.imgur.com/KSHkVzP.png)

Sorting by Account

### Edit Record

Back at view record, the user can edit amount, type, and account of the data.

Because of inheritance tax law, your inheritance has decreased by 75%. We are going to edit the amount of the inheritance.

![EditRecords](https://i.imgur.com/dGaqLfD.png)

First we find the inheritance from the view records menu and type "e" to go to the edit records menu.

![EditAmount](https://i.imgur.com/oeO2PLs.png)

We choose amount

![EditAmount1](https://i.imgur.com/GDd2IpR.png)

and enter 50000 to change the data.

### Filter Record

The user can filter the records to only see what the user want to see.

![FilterRecord](https://i.imgur.com/LVsxHmr.png)

Let's say we only want to see the data for the purchases of games.

We type "1" to choose type and write "Game" to find all the records that have the game type.

![FilterRecord1](https://i.imgur.com/y779Zbs.png)

From here, the user can further sort or edit the filtered data like in the view records menu.

### Income/Expense Report

From the main menu, going into "s" statistics gives you 3 options of statistical reports. The income and expense reports give you detailed information on the amount of money that comes to you and goes out from you.

![Income](https://i.imgur.com/vArKH9w.png)

Clicking on income first gives you the total income. 

![IncomeInheritance](https://i.imgur.com/iMTAYiA.png)

From here, you can type "s" to get a more detailed report comparing your income in a particular area to your total income.

![Expense](https://i.imgur.com/HyJQfVJ.png)

Expense reports works the same way with income reports.

### Graphs

![Graph](https://i.imgur.com/oYnEjXY.png)

You can create a bar graph comparing your income and expenses by using the graphs function. Choose a slot to add a graph into.

![Graph1](https://i.imgur.com/481Zoij.png)

Pick one of the statistics that you want to be shown on the graph.

![Graph2](https://i.imgur.com/aYzaEu4.png)

It will fill the screen (i.e. max) for the first data but will resize as more data is inputted into the other bar slots.

![Graph3](https://i.imgur.com/CtUv6BN.png)

Feel free to put different data into different slots.

### Budget Planner

![Bud1](https://i.imgur.com/4CCpz1N.png)

The special thing about our budget setter is that the user can specify the number of days the user want to budget for and set the amount.

![Bud2](https://i.imgur.com/o6NzDnc.png)

For example, I will set a week long 300 dollar budget plan.

![Bud3](https://i.imgur.com/HIV1XKI.png)

Say 43 seconds later, I make a 130.5 dollar purhcase and add it through the function add records. Then in my budgeting plan, it will say the remaining amount that I can spend for the next 6 days 23 hours 59 minutes and 17 seconds.

![Bud4](https://i.imgur.com/4fl3d2L.png)

However, if I spend more than my remaining amount, I will get an alarm in the budgeting menu that I have overspent.

![Bud5](https://i.imgur.com/4CCpz1N.png)

Then, I can type "r", exit, and come back to the budgeting function to remove the old plan and set a new one.

### Configurations

![conf1](https://i.imgur.com/E1dzTX1.png)

The last yet defining feature of our program is the ability to expand the height and width of our interface based on the user's terminal window. If you don't want to keep pressing "n"(next page) in the view records menu to see the rest of the data, go to configurations and increase your rows. If you want to compare the data in your graphs more precisely, go to configurations and increase your columns. Make sure to drag your terminal to the correct length if you decide to change the values through the configurator.

## Input Specifications

If you want to manually change the data records through the text file, please find "data.txt" and write the data on the text file like this (**with** the first line of text if there is data starting from the 2nd line or **without** the first line of text if there is no data):
```
Amount,Type,Account,Day,Month,Year,Hour,Minutes,Seconds
30000,Salary,Bank Card,26,4,2019,1,2,23,
-2599,Smartphone,Bank Card,13,9,2018,23,12,9,
```

For budgeting, the "budgeting.txt" file will look like this if you have inputted a budgeting plan in the system and nothing if there is no plan in place:
```
Day,Month,Year,Hour,Minute,Second,periodSeconds,budgetAmount
27,3,119,22,36,36,604800,300,
```
