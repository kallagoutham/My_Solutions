SELECT Id FROM Books WHERE Id in (SELECT BooksId FROM BoughtBooks GROUP BY BooksId HAVING COUNT(*)>2);
