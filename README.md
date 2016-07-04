# DataBaseQueryBuilder
### Simple way to create queries for SQLite

The intent of the project is to facilitate the creation of query strings for SQLite. 
The project was made with Test Driven Development. Unit tests are done using Google test library.

### Usage:

###### Example 1:
We want to create query string to select all the records from table "Employee" where Salary is Less or Equal than 20000.

<br><code>string q = DataBaseQueryBuilder.</code>
<br><code>            SelectAll().</code>
<br><code>            From("Employee").</code>
<br><code>            WhereLessOrEqualThan("Salary", 20000).</code>
<br><code>            Build();</code>

q will equate to:

<br><code>SELECT *</code>
<br><code>FROM Employee</code>
<br><code>WHERE (Salary <= 20000);</code>

###### Example 2:
We want to create query string to select Name and Last Name from table "Employee" where Salary is greater than 20000 and less than 50000 Ordered by "City" ascending.

<br><code>string q = DataBaseQueryBuilder.</code>
<br><code>            Select("Name").</code>
<br><code>            Select("Last Name").</code>
<br><code>            From("Employee").</code>
<br><code>            WhereGreaterThan("Salary", 20000).</code>
<br><code>            And().</code>
<br><code>            WhereLess("Salary", 50000).</code>
<br><code>            OrderBy("City").</code>
<br><code>            Asc().</code>
<br><code>            Build();</code>

q will equate to:
<br><code>SELECT Name, Last Name</code>
<br><code>FROM Employee</code>
<br><code>WHERE (Salary > 20000 AND Salary < 50000)</code>
<br><code>ORDER BY City ASC;</code>

###### Example 3:
We want to create query string to select Name and Age from table "Employee" where Company begins with "Ar".

<br><code>string q = DataBaseQueryBuilder.</code>
<br><code>            Select("Name").</code>
<br><code>            Select("Age").</code>
<br><code>            From("Employee").</code>
<br><code>            WhereLike("Company", "Ar%").</code>
<br><code>            Build();</code>

q will equate to:
<br><code>SELECT Name, Last Name</code>
<br><code>FROM Employee</code>
<br><code>WHERE (Company Like "Ar%");</code>
