# Write your MySQL query statement below
# SELECT Visits.customer_id, 
# COUNT(Visits.visit_id) as count_no_trans 
# FROM Visits LEFT JOIN  Transactions ON 
# Visits.visit_id= Transactions.visit_id 
# WHERE Transactions.transaction_id IS NULL 
# GROUP BY Visits.customer_id

select v.customer_id,count(v.visit_id)as count_no_trans from Visits v left join Transactions t on v.visit_id=t.visit_id where t.transaction_id is null group by customer_id;