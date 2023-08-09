WITH cte AS (
    SELECT stock_name, SUM(price) AS price
    FROM Stocks
    WHERE operation = 'Sell'
    GROUP BY stock_name
),
cte2 AS (
    SELECT stock_name, SUM(price) AS price
    FROM Stocks
    WHERE operation = 'Buy'
    GROUP BY stock_name
)
SELECT cte.stock_name, (cte.price - cte2.price) AS capital_gain_loss
FROM cte
LEFT JOIN cte2 ON cte.stock_name = cte2.stock_name;
