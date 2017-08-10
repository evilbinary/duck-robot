
function showMsgBox(msg) {
    if (window.bridge) {
        window.bridge.showMsgBox(msg)
    }else{
        console.log('bridge is null');
    }
}

function myInterval(){
    sendMessage(getFriendByNick('problue'),"hello");
}

function showMessage(msg) {
    console.log('showMessage');
    console.log(jq);
    //setInterval("myInterval()",1000);
    return jq;
}

jq('body').css('display','none');

jq(document).ready(function(e){
    var iframe = document.getElementsByTagName("iframe")[0];
    console.log(iframe);
    var f=jq(iframe);
    f.css('width','0');
    f.css('height','0');
    if (iframe.attachEvent) {
        iframe.attachEvent("onload", function() {
            frameLoad(iframe);
        });
    } else {
        iframe.onload = function() {
            frameLoad(iframe);
        };
    }

});

function showQR(qrSrc){
    jq('.login-title').text("鸭子机器人");
    jq('body').css('display','block');

    jq(document.body).append("<div id='qrcode' style=\"position:fixed;position: fixed;z-index: 99999;width: auto;height: auto;left: 30%;top: 30%;\"/ > \
                        <div style='display:block;margin-bottom:10px;text-align:center;'></div> \
                        <img src='"+qrSrc+"'  style='width:180px;height:auto;' > </div>");
    jq('#container').bind('DOMNodeInserted', function(e) {
        jq('#qrcode').hide();
    });

    init();
    registerMessage(function(pollMsg){
        console.log(pollMsg);
        if(pollMsg.poll_type=='discu_message'){
            var gid=pollMsg.value.from_uin;
            var uid=pollMsg.value.send_uin;
            var code=pollMsg.value.group_code;

            var groupName=getGroupNameByGid(pollMsg.value.from_uin);
            var nickName=getGroupUserNick(gid,uid,code);
            var message=pollMsg.value.content[1]||pollMsg.value.content[0];

            console.log(groupName+'=>'+nickName+' '+ message);
            //sendDiscussMessage(pollMsg.from_uin,pollMsg.value.content[1]);
        }else if(pollMsg.poll_type=='group_message'){
            var gid=pollMsg.value.from_uin;
            var uid=pollMsg.value.send_uin;
            var code=pollMsg.value.group_code;

            var groupName=getGroupNameByGid(pollMsg.value.from_uin);
            var nickName=getGroupUserNick(gid,uid,code);
            var message=pollMsg.value.content[1]||pollMsg.value.content[0];
            if(bridge.recieveGroupMessage){
                bridge.recieveGroupMessage(gid,uid,groupName,nickName,message);
            }
            console.log(groupName+'=>'+nickName+' '+ message);
            //sendGroupMessage(pollMsg.from_uin,pollMsg.value.content[1]);
        }
    });
}

var checkQrId;
function checkQr(){
    var iframe=jq('iframe');
    var qrSrc=iframe.contents().find('#qrlogin_img').attr('src');
    console.log(qrSrc);
    if(qrSrc!=undefined){
        clearInterval(checkQrId);
        showQR(qrSrc);
    }

}


var isFrameLoad=false;
function frameLoad(frame){
    var iframe=jq('iframe');
    var qrSrc=iframe.contents().find('#qrlogin_img').attr('src');
    iframe.css('width','0');
    iframe.css('height','0');

    //showMsgBox(JSON.stringify(jq('img').attr('src')));
    //    console.log(JSON.stringify(frame.innerHTML) );


    if(isFrameLoad==false){
        console.log('frame is load');
        console.log('qrSrc='+qrSrc);

        isFrameLoad=true;
        window.bridge.loadFrame();
        checkQrId=setInterval("checkQr()",1000);
    }
}

function getGroupUserNick(gid,uid,code){
    var user=getGroupUser(gid,uid,code);
    if(user){
        return user.nick;
    }
    return '';
}

function getGroupUser(gid,uid,code){
    var from_group=mq.model.chat.m_model.getGroupByGid(gid,uid);
    if(from_group.members==undefined ){
        mq.model.chat.m_model.getGroupInfoList(from_group.code)
    }
    var from_group_members = from_group.members || [];
    var membersLen = from_group_members.length || 0;
    for( var k = 0; k < membersLen; k++){
        if( from_group_members[k].uin == uid ){
            return  from_group_members[k];
        }
    }
}

function sendGroupMessage(gid,msg){
    var param={"group_uin":gid,
        "content":"[\""+msg+" \",[\"font\",{\"name\":\"宋体\",\"size\":10,\"style\":[0,0,0],\"color\":\"000000\"}]]",
        "face":0,};
    mq.model.chat.sendGroupMsg(param);
}

function sendDiscussMessage(did,msg){
    var param={"did":did,
        "content":"[\""+msg+" \",[\"font\",{\"name\":\"宋体\",\"size\":10,\"style\":[0,0,0],\"color\":\"000000\"}]]",
        "face":0,};
    mq.model.chat.sendDiscussMsg(param);
}

function sendMessage(toUin,msg){
    console.log('sendMessage');
    mq.model.chat.sendMsg({to:toUin,
                              content:'[\"'+msg+'\",[\"font\",{\"name\":\"宋体\",\"size\":10,\"style\":[0,0,0],\"color\":\"000000\"}]]',
                              face:0
                          });
    //mq.model.buddylist.getSelfUin();
    //mq.model.chat
}
function getFriendList(){
    return mq.model.buddylist.getFriends();
}
function getFriendByNick(name){
    var a=mq.model.buddylist.getFriends();
    for(var i=0;i<a.length;i++){
        if(a[i].nick ==name){
            //console.log(a[i].account)
            return a[i].uin;
        }
    };
}
function getFriendByUin(uin){
    return mq.model.buddylist.getFriendByUin
}

function getGroupInfoByGid(gid){
    return mq.model.buddylist.getGroupByGid(gid);
}
function getGroupNameByGid(gid){
    return mq.model.buddylist.getGroupByGid(gid).name;
}

var messagePolls=[];

function registerMessage(fun){
    if(typeof fun=='function'){
        messagePolls.push(fun);
    }
}
var events={};
function registerEvent(name,handler){
    events['name']=handler;
}

function init(){
    var eventOn=JM.event.on;
    JM.event.on=function(obj,evtType,handler){
        newhandler=handler;
        if(evtType ==='receiveMessage'){
            newhandler=function(pollMsg){
                for(var i=0;i<messagePolls.length;i++){
                    if( (typeof messagePolls[i])=='function'){
                        messagePolls[i](pollMsg);
                    }
                }
                handler(pollMsg);
            }
        }
        eventOn(obj,evtType,newhandler);
    }
}




