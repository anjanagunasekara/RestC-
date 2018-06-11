function post(path, params, method) {
    method = method || "post"; // Set method to post by default if not specified.
    
    var value1 = $("#value1").val();
    var value2 = $("#value2").val();
    var pathParams = "val1="+value1+"&val2="+value2;
    
    path += pathParams;

    $.ajax({
      url: path,
      type: 'POST',
      dataType : 'json',
        success : function (response) {
            $("#answer").val(response);
        }
    });
}