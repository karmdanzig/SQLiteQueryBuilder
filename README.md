# DataBaseQueryBuilder
### Simple way to create queries for SQLite

The intent of the project is to facilitate the creation of query strings for SQLite by using functions as normal SQL words, for instance Select() as a SELECT clause or Insert() as a INSERT. The aim of this is to use SQLite without writing the entire query string and using predefined less error-prone routines.

The project was developed with Test Driven Development. Unit tests are done using Google test library.

### Usage:

###### Example 1:
Select all the records from table "Employee" where Salary is Less or Equal than 20000.

<pre><code>string q = DataBaseQueryBuilder.</code>
<code>            SelectAll().</code>
<code>            From("Employee").</code>
<code>            WhereLessOrEqualThan("Salary", 20000).</code>
<code>            Build();</code></pre>
q will equate to:
<pre><code>SELECT *</code>
<code>FROM Employee</code>
<code>WHERE Salary <= 20000;</code></pre>

###### Example 2:
Select Name and Last Name from table "Employee" where Salary is greater than 20000 and less than 50000 Ordered by "City" ascending.

<pre><code>string q = DataBaseQueryBuilder.</code>
<code>            Select("Name").</code>
<code>            Select("Last Name").</code>
<code>            From("Employee").</code>
<code>            WhereGreaterThan("Salary", 20000).</code>
<code>            And().</code>
<code>            WhereLessThan("Salary", 50000).</code>
<code>            OrderBy("City").</code>
<code>            Asc().</code>
<code>            Build();</code></pre>

q will equate to:
<pre><code>SELECT Name, Last Name</code>
<code>FROM Employee</code>
<code>WHERE Salary > 20000 AND Salary < 50000</code>
<code>ORDER BY City ASC;</code></pre>

###### Example 3:
Select Distinct Name and Age from table "Employee" where Company does not begin with "Ar".

<pre><code>string q = DataBaseQueryBuilder.</code>
<code>            Select("Name").</code>
<code>            Select("Age").</code>
<code>            Distinct().</code>
<code>            From("Employee").</code>
<code>            WhereNotLike("Company", "Ar%").</code>
<code>            Build();</code></pre>

q will equate to:
<pre><code>SELECT DISTINCT Name, Last Name</code>
<code>FROM Employee</code>
<code>WHERE Company NOT LIKE 'Ar%';</code></pre>
