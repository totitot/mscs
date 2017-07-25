
$(document).ready(function(){
	console.log("Hello World");
});

$(".bin_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-1\.]/g, function(str){
		return '';
	}));
});

$("#bin_input").keyup(function(){
	var $th = $(this);
	$(".dec_input").val(binToDec($th.val()));
	$("#hex_input").val(binToHex($th.val()));
	$(".oct_input").val(binToOct($th.val()));
});

$(".hex_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-9a-fA-F\.]/g, function(str){
		return '';
	}));
});

$("#hex_input").keyup(function(){
	var $th = $(this);
	var bin = hexToBin($th.val());
	$("#bin_input").val(bin);
});

$(".oct_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-7\.]/g, function(str){
		return '';
	}));
});

$(".dec_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-9]/g, function(str){
		return '';
	}));

});


function binToDec(str){
	var ret = 0;
	if( str.length > 1 ){
		for( i = 0; i < str.length; i++ ){
			ret+= parseInt(str.charAt(i),10)*Math.pow(2,str.length-1-i);
		}
	}
	else{
		ret = str;
	}
	return ret;
}

function binToHex(str){
	var ret = "";
	console.log(" ");

	if( str.length % 4 != 0 ){
		var padlen = (4-(str.length%4));
		for( i = 0; i < padlen; i++ ){
			str = "0".concat(str);
		}
		console.log(str.length+" "+str);
	}

	
	for(i = 0; i < (str.length/4);i++ ){
		dum = 0;
		for( j = 0; j < 4; j++ ){
			dum += parseInt(str.charAt(i*4+j),10)*Math.pow(2,3-j);
		}
		if( dum > 9 ){
			switch(dum-9){
				case 1: dum = "A"; break;
				case 2: dum = "B"; break;
				case 3: dum = "C"; break;
				case 4: dum = "D"; break;
				case 5: dum = "E"; break;
				case 6: dum = "F"; break;
			}
		}
		ret = ret.concat(dum);
		console.log(ret);
	}
	
	return ret;
}

function binToOct(str){
	var ret = "";
	console.log(" ");

	if( str.length % 3 != 0 ){
		padlen = (3-(str.length%3));
		for( i = 0; i < padlen; i++ ){
			str = "0".concat(str);
		}
		console.log(str.length+" "+str);
	}

	
	for(i = 0; i < (str.length/3);i++ ){
		dum = 0;
		for( j = 0; j < 3; j++ ){
			dum += parseInt(str.charAt(i*3+j),10)*Math.pow(2,2-j);
		}
		ret = ret.concat(dum);
		console.log(ret);
	}
	
	return ret;
}

function hexToBin(str){
	var ret = "";
	console.log(" ");
	str = str.toUpperCase();
	for( i = 0; i < str.length; i++ ){
		var dum = str.charAt(i);
		console.log(dum);
		if(dum == "A") dum = 10;
		if(dum == "B") dum = 11;
		if(dum == "C") dum = 12;
		if(dum == "D") dum = 13;
		if(dum == "E") dum = 14;
		if(dum == "F") dum = 15;
		console.log(dum);
		for( i = 0; i < 4; i++ ){
			ret = ret.concat((dum&(1<<3-i))>>(3-i));
			console.log(ret);
		}
	}
	console.log(ret);
	return ret;
}
