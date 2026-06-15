CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N = N-1;
  RETURN (
        select 
            salary
        from Employee
        group by salary
        order by salary desc
        limit 1
        offset N
    

  );
END