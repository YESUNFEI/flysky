;(function () {
  /*********************** Prepare for ***********************/
  var universalLink = 'https://appd.zjzwfw.gov.cn/d/?zwfw://'
  var scheme = 'zwfw://'
  var userAgent = window.navigator.userAgent.toLowerCase()
  var isWechat = /micromessenger/.test(userAgent)
  var isAndroid = /android/.test(userAgent)
  var isIOS = /iphone|ipad/.test(userAgent)
  var btn1 = document.getElementById('downloadBtn1')
  var btn2 = document.getElementById('downloadBtn2')
  var urlGroup = {
    android: "https://zwfw-app.oss-cn-hangzhou.aliyuncs.com/App/zjGovernment.apk",
    appTencent: 'http://a.app.qq.com/o/simple.jsp?pkgname=com.hanweb.android.zhejiang.activity&channel=0002160650432d595942&fromcase=60001',
    ios: "https://itunes.apple.com/cn/app/zhe-jiang-zheng-wu-fu-wu/id910260096?mt=8"
  }
  
  
  var openLink = function (url) { window.location.href = url }
  var getQuery = function (name) {
    var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)");
    var r = window.location.search.substr(1).match(reg);
    if (r != null) return unescape(r[2]); return null;
  }
  var url = getQuery('url')
  var schemeJump = function () {
    var iframe = document.createElement('iframe')
    iframe.style.display = 'none'
    if(url) {
      iframe.src =  scheme+'app?url='+url 
    } else {
      iframe.src =  scheme
    }
    document.documentElement.appendChild(iframe)
    window.setTimeout(function () {
      document.documentElement.removeChild(iframe)
      openLink(urlGroup.android)
      // var symbol = window.location.href.indexOf('?') === -1 ? '?' : '&'
      // var str = symbol + 'jumped=1'
      // window.location.href += str
    }, 1500)
  }
  var isHasJumped = getQuery('jumped')
  var weixinJumpBrowser = function () {
    document.getElementById('tips').style.display = 'block'
  }


  /************************** START **************************/

  /* 点击执行 */
  var perform = function () {
    // if (isWechat) {
    //   weixinJumpBrowser()
    //   return false
    // } 

    /* 如果是ios 先尝试跳 universalLink */
    isIOS && window.setTimeout(openLink(universalLink), 200)

    /* 如果android 判断是否是微信 */
    isAndroid && isWechat && weixinJumpBrowser()

    /* 是微信, 不继续执行 */
    if (isWechat) return 'is wechat!'
    schemeJump()
  }
  
  /* 点击下载按钮 */
  btn1.addEventListener('click', perform, false)
  btn2.addEventListener('click', perform, false)

  var ua =  navigator.userAgent.toLowerCase();
 
  if(ua.search('dtdream') !== -1 && url){
      window.location.replace(url)
  } else if(isWechat) {
    weixinJumpBrowser()
  }

  var from = getQuery('from')
  var isappinstalled = getQuery('isappinstalled')
  if(from || isappinstalled) {
    if(url) {
      window.location.href = window.location.href.split('?')[0] + '?url=' + url
    } else {
      window.location.href = window.location.href.split('?')[0]    
    }
  }
 
  var port =  window.location.protocol === "http:" ? 8088 : 7088
  //微信内二次分享
  window.axios({
    method: 'get',
    // url: `http://120.26.168.214:8088/app_api/invitation/weixing`,
    url: window.location.protocol + '//unibase.zjzwfw.gov.cn:'+port+'/app_api/invitation/weixing',
    params: {
      url: window.location.href.split('#')[0]
    }
  }).then(function (res) {
    var appId = res.data.data.appId
    var timestamp = res.data.data.timestamp
    var nonceStr = res.data.data.nonceStr
    var signature = res.data.data.sign
    wx.config({
      // beta: true,
      appId: appId,
      timestamp: timestamp,
      nonceStr: nonceStr,
      signature: signature,
      jsApiList: [
        'onMenuShareTimeline',
        'onMenuShareAppMessage',
        'onMenuShareQQ',
        'onMenuShareWeibo',
        'onMenuShareQZone'
      ]
    })
    wx.ready(function () {
      wx.checkJsApi({
        jsApiList: [
          'onMenuShareTimeline',
          'onMenuShareAppMessage',
          'onMenuShareQQ',
          'onMenuShareWeibo',
          'onMenuShareQZone'
        ], // 需要检测的JS接口列表，所有JS接口列表见附录2,
        success: function (res) {
          console.log(JSON.stringify(res))
          console.log('check pass')
          // 以键值对的形式返回，可用的api值true，不可用为false
          // 如：{"checkResult":{"chooseImage":true},"errMsg":"checkJsApi:ok"}
        },
        fail: function (error) {
          console.log('check error')
          console.log(error)
        }
      })

      // 分享给微信朋友
      wx.onMenuShareAppMessage({
        title: '浙江政务服务网，伴你一生大小事', // 分享标题
        desc: '不排队，不跑腿，办事就这么简单！', // 分享描述
        link: location.href, // 分享链接
        imgUrl: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20171103014536244_56.png', // 分享图标
        type: 'link', // 分享类型,music、video或link，不填默认为link
        dataUrl: '', // 如果type是music或video，则要提供数据链接，默认为空
        success: function () {

        },
        cancel: function () {

        }
      })

      // 分享到微信朋友圈
      wx.onMenuShareTimeline({
        title: '浙江政务服务网，伴你一生大小事', // 分享标题
        desc: '不排队，不跑腿，办事就这么简单！', // 分享描述
        link: location.href, // 分享链接
        imgUrl: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20171103014536244_56.png', // 分享图标
        type: 'link', // 分享类型,music、video或link，不填默认为link
        dataUrl: '', // 如果type是music或video，则要提供数据链接，默认为空
        success: function () {

        },
        cancel: function () {
          // 用户取消分享后执行的回调函数
        }
      })

      // 分享到QQ
      wx.onMenuShareQQ({
        title: '浙江政务服务网，伴你一生大小事', // 分享标题
        desc: '不排队，不跑腿，办事就这么简单！', // 分享描述
        link: location.href, // 分享链接
        imgUrl: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20171103014536244_56.png', // 分享图标
        type: 'link', // 分享类型,music、video或link，不填默认为link
        dataUrl: '', // 如果type是music或video，则要提供数据链接，默认为空
        success: function () {

        },
        cancel: function () {
          // 用户取消分享后执行的回调函数
        }
      })
      // 分享到微博
      wx.onMenuShareWeibo({
        title: '浙江政务服务网，伴你一生大小事', // 分享标题
        desc: '不排队，不跑腿，办事就这么简单！', // 分享描述
        link: location.href, // 分享链接
        imgUrl: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20171103014536244_56.png', // 分享图标
        type: 'link', // 分享类型,music、video或link，不填默认为link
        dataUrl: '', // 如果type是music或video，则要提供数据链接，默认为空
        success: function () {

        },
        cancel: function () {
          // 用户取消分享后执行的回调函数
        }
      })
      // 分享到QQ空间
      wx.onMenuShareQZone({
        title: '浙江政务服务网，伴你一生大小事', // 分享标题
        desc: '不排队，不跑腿，办事就这么简单！', // 分享描述
        link: location.href, // 分享链接
        imgUrl: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20171103014536244_56.png', // 分享图标
        type: 'link', // 分享类型,music、video或link，不填默认为link
        dataUrl: '', // 如果type是music或video，则要提供数据链接，默认为空
        success: function () {

        },
        cancel: function () {
          // 用户取消分享后执行的回调函数
        }
      })

      console.log('ready')
    })

    wx.error(function (res) {
      console.log('error')
      console.log(res)
    })
  })

})()