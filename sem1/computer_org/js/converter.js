////////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kenth.crisolo@gmail.com
//
////////////////////////////////

var bin;
$(document).ready(function(){
	console.log("Hello World");
});

$(".bin_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-1\.]/g,''));
	$th.val($th.val().replace(/(\..*)\./g, '$1'));
});

$("#bin_input").keyup(function(){
	var $th = $(this);
	bin = $th.val();
	$(".dec_input").val(binToDec(bin));
	$("#hex_input").val(binToHex(bin));
	$(".oct_input").val(binToOct(bin));
});

$(".hex_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-9a-fA-F\.]/g,''));
	$th.val($th.val().replace(/(\..*)\./g, '$1'));
});

$("#hex_input").keyup(function(){
	var $th = $(this);
	bin = hexToBin($th.val());
	$("#bin_input").val(bin);
	$(".dec_input").val(binToDec(bin));
	$(".oct_input").val(binToOct(bin));
});

$(".oct_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-7\.]/g,''));
	$th.val($th.val().replace(/(\..*)\./g, '$1'));
	bin = octToBin($th.val());
	$("#bin_input").val(bin);
	$("#hex_input").val(binToHex(bin));
	$(".dec_input").val(binToDec(bin));
});

$(".dec_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-9]/g,''));
	$th.val($th.val().replace(/(\..*)\./g, '$1'));
	bin = decToBin($th.val());
	$("#bin_input").val(bin);
	$("#hex_input").val(binToHex(bin));
	$(".oct_input").val(binToOct(bin));
});


function binToDec(str){
	var ret = 0;
	if( str.length > 1 ){
		var period = str.indexOf(".");
		if( period == -1 ){
			for( i = 0; i < str.length; i++ ){
				ret+= parseInt(str.charAt(i),10)*Math.pow(2,str.length-1-i);
			}
		}
		else{
			var intstr = str.slice(0,period);
			var fracstr = str.slice(period+1);
			ret = binToDec(intstr) + "." + fracBinToDec(fracstr);
		}
	}
	else{
		ret = str;
	}
	return ret;
}

function fracBinToDec(str){
	var ret = 0;
	for( i = 0; i < str.length; i++ ){
		ret += parseInt(str.charAt(i),10)*Math.pow(2, -(i+1));
	}
	ret = String(ret);
	ret = ret.slice(2);
	return ret;
}

function binToHex(str){
	var ret = "";

	var period = str.indexOf(".");
	if( period == -1 ){
		if( str.length % 4 != 0 ){
			var padlen = (4-(str.length%4));
			for( i = 0; i < padlen; i++ ){
				str = "0".concat(str);
			}
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
		}
	}
	else{
		var intstr = str.slice(0,period);
		var fracstr = str.slice(period+1);
		ret = binToHex(intstr)+"."+fracBinToHex(fracstr);
	}
	
	return ret;
}

function fracBinToHex(str){
	var ret = "";
	if( str.length % 4 != 0 ){
		var padlen = (4-(str.length%4));
		for( i = 0; i < padlen; i++ ){
			str = str.concat("0");
		}
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
	}
	return ret;
}


function binToOct(str){
	var ret = "";

	var period = str.indexOf(".");
	if( period == -1 ){
		if( str.length % 3 != 0 ){
			padlen = (3-(str.length%3));
			for( i = 0; i < padlen; i++ ){
				str = "0".concat(str);
			}
		}

		
		for(i = 0; i < (str.length/3);i++ ){
			dum = 0;
			for( j = 0; j < 3; j++ ){
				dum += parseInt(str.charAt(i*3+j),10)*Math.pow(2,2-j);
			}
			ret = ret.concat(dum);
		}
	}
	else{
	}
	
	return ret;
}

function hexToBin(str){
	var ret = "";
	str = str.toUpperCase();
	for( i = 0; i < str.length; i++ ){
		var dum = str.charAt(i);
		if(dum == "A") dum = 10;
		if(dum == "B") dum = 11;
		if(dum == "C") dum = 12;
		if(dum == "D") dum = 13;
		if(dum == "E") dum = 14;
		if(dum == "F") dum = 15;
		dum = parseInt(dum,10);
		for( j = 0; j < 4; j++ ){
			ret = ret.concat((dum&(1<<3-j))>>(3-j));
		}
	}
	return ret;
}

function decToBin(str){
	var ret = "";
	var dum = parseInt(str,10);
	var numlen = Math.ceil(Math.log(dum+1)/Math.LN2);
	for( i = 0; i < numlen; i++ ){
		ret = ret.concat((dum&(1<<numlen-1-i))>>(numlen-1-i));
	}
	return ret;
}

function octToBin(str){
	var ret = "";
	for( i = 0; i < str.length; i++ ){
		var dum = str.charAt(i);
		dum = parseInt(dum,10);
		for( j = 0; j < 3; j++ ){
			ret = ret.concat((dum&(1<<2-j))>>(2-j));
		}
	}
	return ret;
}

