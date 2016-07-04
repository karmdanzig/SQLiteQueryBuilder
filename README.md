# DataBaseQueryBuilder
Simple way to create queries for SQLite

The intent of the project is to facilitate the creation of query strings for SQLite. 
The project was made with Test Driven Development. Unit tests are done using Google test library.

Usage:

Example 1:
We want to create query string to select all the records from table "Employee" where Salary is Less or Equal than 20000.

string q = DataBaseQueryBuilder.SelectAll().From("Employee").WhereLessOrEqualThan("Salary", 20000).Build();

q will equate to:
SELECT *
FROM Employee
WHERE (Salary <= 20000);

Example 2:
We want to create query string to select Name and Last Name from table "Employee" where Salary is greater than 20000 and less than 50000 Ordered by "City" ascending.

string q = DataBaseQueryBuilder.Select("Name").Select("Last Name").From("Employee").WhereGreaterThan("Salary", 20000).And().WhereLess("Salary", 50000).OrderBy("City").Asc().Build();

q will equate to:
SELECT Name, Last Name
FROM Employee
WHERE (Salary > 20000 AND Salary < 50000)
ORDER BY City ASC;

Example 3:
We want to create query string to select Name and Age from table "Employee" where Company begins with "Ar".

string q = DataBaseQueryBuilder.Select("Name").Select("Age").From("Employee").WhereLike("Company", "Ar%").Build();

q will equate to:
SELECT Name, Last Name
FROM Employee
WHERE (Company Like "Ar%");
