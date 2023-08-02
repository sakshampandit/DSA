# Write your MySQL query statement below
select b.unique_id as unique_id,a.name as name from Employees  a left join EmployeeUNI  b on a.id=b.id;
# select 
# eu.unique_id as unique_id, e.name as name
# from Employees e left join EmployeeUNI eu on e.id = eu.id