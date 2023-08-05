# Write your MySQL query statement below
select a.name from Employee a inner join (select b.managerId from Employee b group by b.managerId having count(b.managerId)>=5) b on a.id=b.managerId;

