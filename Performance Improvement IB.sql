/* YOUR QUERY GOES HERE
   Example: SELECT * FROM EMPLOYEE; 
*/
SELECT      currTest.TestId
FROM        Tests currTest
INNER JOIN  Tests prevTest ON prevTest.TestId = currTest.TestId-1 AND currTest.Marks > prevTest.Marks;
