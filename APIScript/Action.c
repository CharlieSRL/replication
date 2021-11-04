Action()
	
{
	int i = 0;
	web_add_header("authorization","{authorization}");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Expect", 
		"100-continue");
	
	for(i=1000; i>=1; i--)
					{
	lr_save_datetime("%Y-%m-%dT%H:%M:%S", DATE_NOW - (ONE_DAY * i) , "pBeginDateTime");
    lr_output_message(lr_eval_string("2018-12-11T20:10:40"));
    lr_save_datetime("%m/%d/%y", DATE_NOW - (ONE_DAY * i) , "pBUS_DATE");
    lr_output_message(lr_eval_string("12/11/18"));
    lr_save_datetime("%Y-%m-%d", DATE_NOW - (ONE_DAY * i) , "pBusinessDayDate");
    lr_output_message(lr_eval_string("2018-12-11"));
	lr_save_datetime("%Y-%m-%dT%H:%M:%S", DATE_NOW - (ONE_DAY * i) , "pBusinessDayDateTime");
    lr_output_message(lr_eval_string("2018-12-11T05:00:01"));
	lr_save_datetime("%Y-%m-%dT%H:%M:%S", DATE_NOW - (ONE_DAY * i) , "pEndDateTime");
    lr_output_message(lr_eval_string("2018-12-11T20:11:43"));
	lr_save_int(i,"Number");
    lr_output_message(lr_eval_string("{Number}"));
	
    web_add_header("authorization","{authorization}");
    
	lr_start_transaction("01_POS_Data_Load");
	 
	web_custom_request("Transactions_3", 
		"URL=http://anumeshreddyreddygiri1-trial-test.apigee.net/apisystem", 
		"Method=GET", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
        "Body=\"<pSequenceNumber>{pSequenceNumber}{Number}</pSequenceNumber>\\r\\n<pSequenceNumber>{pSequenceNumber}{Number}</pSequenceNumber>\\r\\n<BeginDateTime>2018-12-11T20:10:40</BeginDateTime>\\r\\n<pBUS_DATE>12/11/18</pBUS_DATE>\\r\\n<pBusinessDayDate>2018-12-11</pBusinessDayDate>\\r\\n<pBusinessDayDateTime>2018-12-11T05:00:01</pBusinessDayDateTime>\\r\\n<pEndDateTime>2018-12-11T20:11:43</pEndDateTime>\"",
		LAST);
	


	lr_end_transaction("01_POS_Data_Load", LR_AUTO);
	}
return 0;
}