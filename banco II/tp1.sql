CREATE OR REPLACE FUNCTION  apaga_Product()
RETURNS TRIGGER
AS 
$$

BEGIN

if(SELECT eid FROM product ) <= ('0') THEN
    DELETE FROM product WHERE eid=0;

END IF;

if(SELECT quantity FROM stock) <=('0') THEN
    DELETE FROM stock WHERE quantity =0;

END IF;

RETURN NULL;


	
END;
$$ 

LANGUAGE plpgsql;

