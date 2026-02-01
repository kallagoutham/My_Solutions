select a.player_id, a.device_id from Activity a where (a.player_id,a.event_date) in 
(SELECT A.player_id, min(A.event_date) from Activity A group by A.player_id);
