SELECT M.MEMBER_NAME,R.REVIEW_TEXT,DATE_FORMAT(R.REVIEW_DATE,'%Y-%m-%d') AS REVIEW_DATE
FROM REST_REVIEW AS R
JOIN (
    SELECT B.MEMBER_NAME, B.MEMBER_ID
    FROM REST_REVIEW AS A
    LEFT JOIN MEMBER_PROFILE AS B
    ON B.MEMBER_ID = A.MEMBER_ID
    GROUP BY A.MEMBER_ID
    ORDER BY SUM(REVIEW_SCORE) DESC
    LIMIT 1 
) AS M
ON M.MEMBER_ID = R.MEMBER_ID
ORDER BY REVIEW_DATE, REVIEW_TEXT