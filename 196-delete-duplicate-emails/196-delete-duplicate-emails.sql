# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE b FROM Person a, Person b WHERE a.id<b.id and a.email=b.email;