
-- 2
select d1.nome, max(e1.salario) from empregados e1 join 
departamentos d1 on e1.emp_id=d1.dep_id group by d1.nome;
-- 3
SELECT * FROM programa_bolsa.departamentos;
SELECT d.dep_id,e.nome,e.salario from programa_bolsa.departamentos d join programa_bolsa.empregados e on 
d.dep_id= e.emp_id order by salario desc ;

-- 3
select d.dep_id, e.nome, max(salario) from departamentos d inner join
empregados e on d.dep_id=e.dep_id group by
 salario, d.dep_id,e.nome order by salario desc limit 4 ;
 
--  4
select d.nome ,count(e.nome) from departamentos d  join empregados e on d.dep_id=e.dep_id group by d.nome 
 order by count(e.nome) asc limit 3;
 
 -- 6
select d.nome,count(e.nome) from departamentos d join
empregados e  on d.dep_id=e.dep_id  group by d.nome;

-- 7
select * from departamentos d where not exists(select e.emp_id from empregados e
 where d.dep_id=e.emp_id) ;
 

-- 8
select d.nome, sum(salario) as "salarios pagos" from departamentos d join
empregados e  on d.dep_id=e.dep_id group by d.nome  ;


-- 10
 select e.emp_id,e.nome, d.dep_id,e.salario,AVG(e.salario) as "AVG" from departamentos d join
empregados e on d.dep_id= e.dep_id group by d.dep_id,e.emp_id,e.nome,e.salario ;

-- 11 

select e.nome, d.dep_id,e.salario,AVG(e.salario) as "AVG" from departamentos d join
empregados e on d.dep_id= e.dep_id group by d.dep_id,e.emp_id,e.nome,e.salario ;