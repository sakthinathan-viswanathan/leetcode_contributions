SELECT 
    s1.student_id,
    s1.student_name,
    s2.subject_name,
    COUNT(e1.subject_name) AS attended_exams
FROM Students s1
CROSS JOIN Subjects s2
LEFT JOIN Examinations e1
    ON s1.student_id = e1.student_id
    AND s2.subject_name = e1.subject_name
GROUP BY 
    s1.student_id,
    s1.student_name,
    s2.subject_name
ORDER BY
    s1.student_id,
    s2.subject_name;