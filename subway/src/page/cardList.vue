<template>
  <section class="content">
    <div class="selectCity">
      <span>请领取您所在城市的卡片</span>
      <div id="cityList" @click="cityList()">  
        <img src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180108032903791_21.png" />
        <span>{{city}}</span>
      </div>
    </div>
    <ul>
      <li v-for="card in cards">
        <div class="card">
          <img class="card_bg" src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180109041316140_6.png" />
          <div class="card_info">
            <img class="card_logo" :src="card.logo" />
            <span class="city_name">{{card.city}}</span>
            <div class="ishave" v-show="card.isHave">
              已领取
            </div>
          </div>
        </div>
      </li>
    </ul>
  </section>
</template>

<script>
export default {
  name: 'cardList',
  data () {
    return {
      city: '杭州',
      cards: [
        {city: '杭州地铁通', logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', isHave: true},
        {city: '杭州地铁通', logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', isHave: false},
        {city: '杭州地铁通', logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', isHave: false},
        {city: '杭州地铁通', logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', isHave: false}
      ]
    }
  },
  methods: {
    cityList () {
      let scope = this
      scope.$router.push({path: '/cityList'})
    }
  },
  // 页面挂载
  mounted () {
    // window.dd.biz.busCard.allList({
    //   cityCode: '1123',
    //   onSuccess: function (data) {
    //     // data => {list=[a, b] }
    //     console.log(data)
    //   },
    //   onFail: function () {
    //   // 未授权: 需要跳转到未授权页面
    //   }
    // })
  },
  created () {
    // let scope = this
    document.title = '电子公交卡'
  }
}
</script>

<style scoped lang='scss'>
  @import '../common/style/variable.scss';
  .content {
    @include fill-all;
    padding: 1rem;
    background-color: #f6f8f7;
    .selectCity {
      width: 100%;
      height: 2.5rem;
      text-align: left;
      span {
        font-size: 1.4rem;
        color: #666666;
        line-height: 2.5rem;
      }
      
      #cityList {
        height: 100%;
        float: right;
        text-align: right;
        img {
          height: 2rem;
        }
        span {
          font-size: 1.4rem;
          color: #1492ff;
          line-height: 2.5rem;
        }
      }
    }

    ul li {
      margin-top: 1rem;
      .card {
        width:100%;
        position: relative;
        
        .card_bg {
          width: 100%;
        }
        .card_info {
          position: absolute;
          left:0;
          top:20px;
          width:100%;
          .card_logo {
            width: 3rem;
            border-radius:50%;
            margin-left:20px;
          }
          .city_name {
            color: #fff;
            font-size: 2.3rem;
            position: absolute;
            left: 5.5rem;
            top: 50%;
            transform: translateY(-50%);
          }
          .ishave {
            display:inline-block;
            background-color:rgba(0,0,0,.4);
            border: 1px solid #fff;
            border-radius:1rem;
            color: #fff;
            position: absolute;
            right: 20px;
            top: 50%;
            transform: translateY(-50%);
            width: 5rem;
            height:2rem;
            text-align:center;
            line-height: 2rem;
            font-size: 1.3rem;
          }

        }
      }
    }
  }
</style>
