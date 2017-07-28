////////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
////////////////////////////////

var bin;
var ieee_bin;
$(document).ready(function(){
	console.log("Hello World");
});

$("input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().slice($th.val().search(/[^0]/)));
	$th.val($th.val().replace(/(\..*)\./g, '$1'));
});

$(".bin_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-1\.]/g,''));
});

$("#bin_input").keyup(function(){
	var $th = $(this);
	bin = $th.val();

	var str = $th.val().split('.');
	str[0] = str[0].replace(/(.)(?=(.{4})+$)/g, '$1 ');
	if (str[1]){
		str[1] = str[1].replace(/(.{4})/g, '$1 ');
	}
	$th.val(str.join('.'));

	$(".dec_input").val(binToDec(bin));
	$("#hex_input").val(binToHex(bin));
	$(".oct_input").val(binToOct(bin));

	ieee_bin = binToIEEEBin(bin);
	$("#i3e_bin_input").val(ieee_bin);
	$("#i3e_hex_input").val(binToHex(ieee_bin.replace(/\ */g,'')).replace(/(.{4})/g,'$1 '));
});

$(".hex_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-9a-fA-F\.]/g,''));
});

$("#hex_input").keyup(function(){
	var $th = $(this);

	bin = hexToBin($th.val());

	$th.val(bin_hex_separator($th.val()));

	$("#bin_input").val(bin_hex_separator(bin));
	$(".dec_input").val(dec_separator(binToDec(bin)));
	$(".oct_input").val(oct_separator(binToOct(bin)));

	ieee_bin = binToIEEEBin(bin);
	$("#i3e_bin_input").val(ieee_bin);
	$("#i3e_hex_input").val(binToHex(ieee_bin.replace(/\ */g,'')).replace(/(.{4})/g,'$1 '));
});

$(".oct_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-7\.]/g,''));

	bin = octToBin($th.val());

	$th.val(oct_separator($th.val()));

	$("#bin_input").val(bin_hex_separator(bin));
	$("#hex_input").val(bin_hex_separator(binToHex(bin)));
	$(".dec_input").val(dec_separator(binToDec(bin)));

	ieee_bin = binToIEEEBin(bin);
	$("#i3e_bin_input").val(ieee_bin);
	$("#i3e_hex_input").val(binToHex(ieee_bin.replace(/\ */g,'')).replace(/(.{4})/g,'$1 '));
});

$(".dec_input").keyup(function(){
	var $th = $(this);
	$th.val($th.val().replace(/[^0-9\.\-]/g,''));
	$th.val($th.val().replace(/(\-.*)\-/g, '$1'));
	$th.val($th.val().replace(/([0-9\.]+)\-.*/g, '$1'));

	bin = decToBin($th.val());

	$th.val(dec_separator($th.val()));

	$("#bin_input").val(bin_hex_separator(bin));
	$("#hex_input").val(bin_hex_separator(binToHex(bin)));
	$(".oct_input").val(oct_separator(binToOct(bin)));

	ieee_bin = binToIEEEBin(bin);
	$("#i3e_bin_input").val(ieee_bin);
	$("#i3e_hex_input").val(binToHex(ieee_bin.replace(/\ */g,'')).replace(/(.{4})/g,'$1 '));

});

function dec_separator(s){
	var str = s.split('.');
	str[0] = str[0].replace(/(.)(?=(.{3})+$)/g, '$1,');
	if (str[1]){
		str[1] = str[1].replace(/(.{3})/g, '$1 ');
	}
	return str.join('.');
}

function oct_separator(s){
	var str = s.split('.');
	str[0] = str[0].replace(/(.)(?=(.{3})+$)/g, '$1 ');
	if (str[1]){
		str[1] = str[1].replace(/(.{3})/g, '$1 ');
	}
	return str.join('.');
}

function bin_hex_separator(s){
	var str = s.split('.');
	str[0] = str[0].replace(/(.)(?=(.{4})+$)/g, '$1 ');
	if (str[1]){
		str[1] = str[1].replace(/(.{4})/g, '$1 ');
	}
	return str.join('.');
}


function binToDec(str){
	var ret = 0;
	var period = str.indexOf(".");
	if( period == -1 ){
		for( i = 0; i < str.length; i++ ){
			ret+= parseInt(str.charAt(i),10)*Math.pow(2,str.length-1-i);
		}
		if( (ret > Math.pow(2,31)) && str.length <= 32 ){
			ret = (~ret + 1)*-1;
		}
	}
	else{
		var intstr = str.slice(0,period);
		var fracstr = str.slice(period+1);
		ret = binToDec(intstr) + "." + fracBinToDec(fracstr);
	}
	return String(ret);
}

function fracBinToDec(str){
	var ret = 0;
	if( Number(str) == 0 ){
		ret = str;
	}
	else{
		for( i = 0; i < str.length; i++ ){
			ret += parseInt(str.charAt(i),10)*Math.pow(2, -(i+1));
		}
		ret = String(ret);
		ret = ret.slice(ret.indexOf(".")+1);
	}
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

		ret = bin_hex_converter(str);
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

	return bin_hex_converter(str);
}

function bin_hex_converter(str){
	var ret = "";
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
		
		ret = bin_oct_converter(str);
	}
	else{
		var intstr = str.slice(0,period);
		var fracstr = str.slice(period+1);
		ret = binToOct(intstr)+"."+fracBinToOct(fracstr);
	}

	return ret;
}

function fracBinToOct(str){
	if( str.length % 3 != 0 ){
		padlen = (3-(str.length%3));
		for( i = 0; i < padlen; i++ ){
			str = str.concat("0");
		}
	}
	
	return bin_oct_converter(str);
}

function bin_oct_converter(str){
	var ret = "";
	for(i = 0; i < (str.length/3);i++ ){
		dum = 0;
		for( j = 0; j < 3; j++ ){
			dum += parseInt(str.charAt(i*3+j),10)*Math.pow(2,2-j);
		}
		ret = ret.concat(dum);
	}
	return ret;
}

function hexToBin(str){
	var ret = "";
	str = str.toUpperCase();
	var period = str.indexOf(".");
	if( period == -1 ){
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
				ret = ret.concat(((dum&(1<<3-j))==0?"0":"1"));
			}
		}
	}
	else{
		var intstr = str.slice(0,period);
		var fracstr = str.slice(period+1);
		ret = hexToBin(intstr);
		ret += "."+hexToBin(fracstr);
	}
	if( Number(ret) == 0 ) ret = "0";
	else ret = ret.slice(ret.indexOf("1"));
	return ret;
}

function decToBin(str){
	var ret = "";
	var dum = parseInt(str,10);
	var period = str.indexOf(".");
	if( period == -1 ){
		if( dum < 0 ){
			dum = (Math.pow(2,32))-Math.abs(dum);
		}

		var numlen = Math.ceil(Math.log(dum+1)/Math.LN2);
		for( i = 0; i < numlen; i++ ){
			ret = ret.concat(((dum&(1<<numlen-1-i))==0?"0":"1"));
		}
	}
	else{
		var intstr = str.slice(0,period);
		var fracstr = str.slice(period+1);
		fracstr = "0."+fracstr;
		ret = decToBin(intstr)+"."+fracDecToBin(fracstr);
	}

	if( Number(ret) == 0 ) ret = "0";
	else ret = ret.slice(ret.indexOf("1"));
	return ret;
}

function fracDecToBin(str){
	var ret = "";
	str = Number(str);
	var length = 0;
	while(length < 32){
		str *= 2;
		if( str >= 1 ){
			ret += "1";
			str -= 1;
		}
		else{
			ret += "0";
		}
		length++;
	}
	ret = (ret.slice(0,ret.lastIndexOf("1")+1));
	return ret;
}

function octToBin(str){
	var ret = "";
	var period = str.indexOf(".");
	if( period == -1 ){
		for( i = 0; i < str.length; i++ ){
			var dum = str.charAt(i);
			dum = parseInt(dum,10);
			for( j = 0; j < 3; j++ ){
				ret = ret.concat(((dum&(1<<2-j))==0?"0":"1"));
			}
		}
	}
	else{
		var intstr = str.slice(0,period);
		var fracstr = str.slice(period+1);
		ret = octToBin(intstr)+"."+octToBin(fracstr);
	}
	if( Number(ret) == 0 ) ret = "0";
	else ret = ret.slice(ret.indexOf("1"));
	return ret;
}

function binToIEEEBin(str){
	var period = str.indexOf(".");
	var sign = "0";
	var exp = "";
	var mantissa = "";
	// integer only
	if( Number(str) == 0 ){
		exp = new Array(9).join("0");
		mantissa = new Array(24).join("0");
	}
	else{
		if( period == -1 ){
			// if negative
			if( str.length == 32 && str.charAt(0) == "1" ){
				sign = "1";
			}
			exp = decToBin(String(127+str.slice(str.indexOf("1")).length-1));
			mantissa = str.slice(str.indexOf("1")+1);
		}
		// with fraction
		else{
			var explen = period - str.indexOf("1") - 1;
			exp = decToBin(String(127+explen));
			mantissa = str.replace(".",'').slice(str.indexOf("1")+1);
		}
		if( exp.length < 8 ){
			var lpad = new Array(9-exp.length).join("0");
			exp = lpad.concat(exp);
		}
		if( mantissa.length < 23 ){
			var rpad = new Array(24-mantissa.length).join("0");
			mantissa += rpad;
		}
		if( mantissa.length > 23 ){
			mantissa = mantissa.slice(0,23);
		}
	}

	return sign + " " + exp + " " + mantissa;

}

