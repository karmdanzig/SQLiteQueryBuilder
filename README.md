# SQLiteQueryBuilder
### Simple way to create queries for SQLite

The intent of the project is to facilitate the creation of SQLite queries by using functions named after SQL keywords. For each type of query, it will be possible to use a set of functions with SQL keywords names and they will behave as such. 

In order to use this project, you will need to construct the query following 3 easy steps:

1) Use one of the following types Of query: AlterBuilder, BeginTransactionBuilder, CreateBuilder, CreateIndexBuilder, DeleteBuilder, DropBuilder, EndTransactionBuilder, InsertBuilder, PragmaBuilder, RollbackTransactionBuilder, SelectBuilder, UpdateBuilder.

2) Use any functions available for each type of query. It is recommended to use them in a correct order, like you would on a normal SQL query, for clarity.

3) Use ".Build();" at the end of it.

This will return the correct query as a std::string. See more examples in the Usage section. 

The project was developed in C++ with Test Driven Development. Unit tests were created using Google test library.

### Usage:

###### Example 1:
Select all the records from table "Employee" where Salary is Less or Equal than 20000.

<pre><code>std::string q = SelectBuilder().</code>
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

<pre><code>std::string q = SelectBuilder().</code>
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

<pre><code>std::string q = SelectBuilder().</code>
<code>            Select("Name").</code>
<code>            Select("Age").</code>
<code>            Distinct().</code>
<code>            From("Employee").</code>
<code>            WhereNotLike("Company", "Ar%").</code>
<code>            Build();</code></pre>

q will equate to:
<pre><code>SELECT DISTINCT Name, Age</code>
<code>FROM Employee</code>
<code>WHERE Company NOT LIKE 'Ar%';</code></pre>
