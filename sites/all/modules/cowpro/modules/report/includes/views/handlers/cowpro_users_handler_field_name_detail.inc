<?php

class cowpro_users_handler_field_name_detail extends views_handler_field {
	function render($values) {
		$uid = $this->get_value($values);

		$profile_real_name = cowpro_customer_profile_load_one_row_with_conditions ( $uid, 'real_name' );
		if ($profile_real_name) {
			$real_name = $profile_real_name->name;
		} else {
			$real_name = '';
		}
		$user = user_load($uid);
		$userpath = 'user/' . $user->uid;
		$result = l($user->name . "($real_name)", $userpath);
		return $result;
	}
}
