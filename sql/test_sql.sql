-- t1
-- user_id, user

-- t2
-- tid, user_id, content

with tmp1 as (select user_id, count(tid) as cnt from t2 group by user_id),
tmp2 as (select user_id, cnt from tmp1 order by cnt desc limit 10)
select user, cnt from tmp2 left join t1 on tmp2.user_id = t1.user_id;
