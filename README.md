# DataBaseQueryBuilder
Simple way to create queries for SQLite

The intent of the project is to facilitate the creation of query strings for SQLite. 

Usage:

For example we want to create query string to select all the records from table "Employee" where Salary is Less or Equal than 20.

string q = DataBaseQueryBuilder.SelectAll().From("Employee").WhereLessOrEqualThan("Salary", 20000).Build();

q will equate to:
SELECT *
FROM Employee
Where (Salary <= 20000);
